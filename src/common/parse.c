
#include <stdio.h>
#include <string.h>

#include <common/parse.h>

#define END_OF_FILE -17

static minic_int_t state;
static minic_char_t sbuf[4096];     // 内容缓冲区
static minic_char_t line[8192];     // 行缓冲区

static enum
{
    START, NOTE, ERROR, EMPTY, STR
};

static minic_int_t bc = 0;
static inline cleanbuf() { bc = 0; }
static inline minic_int_t putbuf(char ch)
{
    if(bc < 4095) {
        sbuf[bc++] = ch;
        sbuf[bc] = 0;
    } else {
        return MINIC_FAIL;
    }

    return MINIC_OK;
}

static inline minic_int_t isblank(char ch)
{
    return ch == ' ' || ch == '\t';
}

static inline minic_int_t isalph(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

static inline minic_char_t nextch(FILE *file)
{
    static minic_int_t cursor = 0;
    
    if(line[cursor])
        return line[cursor++];

    if(fgets(line, 8191, file) == NULL)
        return END_OF_FILE;
    
    return '\0';
}

static minic_int_t peekstr(char strhead, const char * strtail, FILE *file)
{
    minic_char_t chbuf[2];

    chbuf[1] = '\0';
    cleanbuf();
    if(strhead != -1) {
        putbuf(strhead);
    }
    while(TRUE) {
        chbuf[0] = nextch(file);
        
        if(strstr(strtail, chbuf)) {
            if(putbuf('\0') == MINIC_OK)
                break;
            return FALSE;
        }

        if(chbuf[0] == '\0' || putbuf(chbuf[0]) == MINIC_FAIL)
            return FALSE;
    }

    return TRUE;
}

// static minic_int_t setwriter(char **writer, minic_config_t *config)
// {
//     if(!strcmp(sbuf, "log_file"))
//         *writer = config->log_file;
//     else if(!strcmp(sbuf, "abstract_sock"))
//         *writer = config->abs_sock;
//     else if(!strcmp(sbuf, "port")) {

//     }

// }

static minic_int_t peekch(char ch, FILE *file)
{
    char c;

    while (TRUE) {
        c = nextch(file);
        if(isblank(c))
            continue;
        if(c == ch)
            break;
        return FALSE;
    }

    return TRUE;
}

static minic_int_t parse(FILE *file, minic_config_t *config)
{
    minic_char_t ch;
    minic_int_t state, write_flag;
    minic_frinode_t *fnode;

    enum { LOG_FILE, ABS_SOCK, PORT, FRIEND_NUM, FRIEND_NAME };

    memset(line, 0, sizeof(line));
    state = START;
    while(TRUE) {
        ch = nextch(file);
        
        switch (state) {
        case START:
            if(ch == '#') state = NOTE;
            else if(isblank(ch) || ch == '\0' || ch == '\r' || ch == '\n') ;
            else if(ch == '[' && peekstr(-1, "]", file)) state = EMPTY;
            else if(isalph(ch) && peekstr(ch, " \t", file) && peekch('=', file) && peekch('\"', file)) {
                if(!strcmp(sbuf, "log_file")) state = STR, write_flag = LOG_FILE;
                else if(!strcmp(sbuf, "sock")) state = STR, write_flag = ABS_SOCK;
                else if(!strcmp(sbuf, "port")) state = STR, write_flag = PORT;
                else if(!strcmp(sbuf, "friend_num")) state = STR, write_flag = FRIEND_NUM;
                else if(!strcmp(sbuf, "friend_name")) state = STR, write_flag = FRIEND_NAME;
                else state = ERROR;
            } else state = ERROR;
            break;
        case NOTE: state = (ch == '\0') ? START : NOTE; break;
        case EMPTY:
            if(ch == '#') state = NOTE;
            else if(ch == '\0') state = START;
            else if(isblank(ch)) ;
            else state = ERROR;
            break;
        case STR:
            if(peekstr(-1, "\"", file)) {
                switch (write_flag) {
                case PORT: state = EMPTY, config->port = atoi(sbuf); break;
                case FRIEND_NUM: state = EMPTY, config->fri_num = atoi(sbuf); break;
                case LOG_FILE: state = EMPTY, strcpy(config->log_file, sbuf); break;
                case ABS_SOCK: state = EMPTY, strcpy(config->abs_sock, sbuf); break;
                case FRIEND_NAME: 
                    fnode = malloc(sizeof(minic_frinode_t));
                    fnode->using = TRUE;
                    fnode->list.prev = fnode->list.next = NULL;
                    state = (addfrinode(fnode, &config->fris) ==MINIC_OK) ? EMPTY : ERROR;
                    break;
                }
            } else state = ERROR;
            break;
        case ERROR: return MINIC_FAIL;
        default: return MINIC_FAIL;
        }
    }

    return MINIC_OK;
}

minic_int_t parseconf(const char *etcfile, minic_config_t *config)  
{
    FILE * file;
    minic_char_t *pch;
    minic_int_t n, state, cursor;

    if(!config)
        return MINIC_FAIL;

    file = fopen(etcfile, "r");
    if(!file)
        return MINIC_FAIL;
    
    return parse(file, config);
}

minic_int_t addfrinode(minic_frinode_t *frino, minic_frinode_t *listhead)
{
    if(!listhead->using) {
        strcpy(listhead->name, frino->name);
        listhead->using = TRUE;
        listhead->list.prev = listhead->list.next = NULL;
        return MINIC_OK;
    }
    
    return insert_list(&frino->list, &listhead->list, listhead->list.next) == MINIC_OK;
}