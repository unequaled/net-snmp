/*
 *Copyright(c)2004,Cisco URP imburses and Network Information Center in Beijing University of Posts and Telecommunications researches.
 *
 *All right reserved
 *
 *File Name: expValueTable.c
 *File Description: expValueTable MIB operation.
 *
 *Current Version:1.0
 *Author:JianShun Tong
 *Date:2004.8.20
 */


/*
 * This file was generated by mib2c and is intended for use as
 * a mib module for the ucd-snmp snmpd agent. 
 */


/*
 * This should always be included first before anything else 
 */
#include <net-snmp/net-snmp-config.h>
#include <ctype.h>
#if HAVE_STDLIB_H
#include <stdlib.h>
#endif

#include <stdio.h>

#if HAVE_STRING_H
#include <string.h>
#else
#include <strings.h>
#endif
#ifdef HAVE_LIMITS_H
#include <limits.h>
#endif


/*
 * minimal include directives 
 */
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "header_complex.h"
#include "expExpressionTable.h"
#include "expValueTable.h"
#include "expObjectTable.h"


/*
 * expValueTable_variables_oid:
 *   this is the top level oid that we want to register under.  This
 *   is essentially a prefix, with the suffix appearing in the
 *   variable below.
 */

static const oid expValueTable_variables_oid[] = {
    1, 3, 6, 1, 2, 1, 90, 1, 3, 1
};

struct s_node {
    unsigned        data;
    struct s_node  *next;
};
typedef struct s_node nodelink;
static FindVarMethod var_expValueTable;

/*
 * variable2 expObjectTable_variables:
 */

static const struct variable2 expValueTable_variables[] = {
    /*
     * magic number        , variable type , ro/rw , callback fn  , L, oidsuffix 
     */
#define	EXPVALUECOUNTER32VAL 2
    {EXPVALUECOUNTER32VAL,  ASN_COUNTER,  NETSNMP_OLDAPI_RONLY,
     var_expValueTable, 2, {1, 2}},
#define	EXPVALUEUNSIGNED32VAL 3
    {EXPVALUEUNSIGNED32VAL, ASN_UNSIGNED, NETSNMP_OLDAPI_RONLY,
     var_expValueTable, 2, {1, 3}},
#define	EXPVALUETIMETICKSVAL 4
    {EXPVALUETIMETICKSVAL,  ASN_UNSIGNED, NETSNMP_OLDAPI_RONLY,
     var_expValueTable, 2, {1, 4}},
#define	EXPVALUEINTEGER32VAL 5
    {EXPVALUEINTEGER32VAL,  ASN_INTEGER,  NETSNMP_OLDAPI_RONLY,
     var_expValueTable, 2, {1, 5}},
#define	EXPVALUEIPADDRESSVAL 6
    {EXPVALUEIPADDRESSVAL, ASN_IPADDRESS, NETSNMP_OLDAPI_RONLY,
     var_expValueTable, 2, {1, 6}},
#define	EXPVALUEOCTETSTRINGVAL 7
    {EXPVALUEOCTETSTRINGVAL, ASN_OCTET_STR, NETSNMP_OLDAPI_RONLY,
     var_expValueTable, 2, {1, 7}},
#define	EXPVALUEOIDVAL  8
    {EXPVALUEOIDVAL,       ASN_OBJECT_ID, NETSNMP_OLDAPI_RONLY,
     var_expValueTable, 2, {1, 8}},
#define	EXPVALUECOUNTER64VAL  9
    {EXPVALUECOUNTER64VAL, ASN_INTEGER,   NETSNMP_OLDAPI_RONLY,
     var_expValueTable, 2, {1, 9}}
};


/*
 * global storage of our data, saved in and configured by header_complex() 
 */
extern struct header_complex_index *expExpressionTableStorage;
extern struct header_complex_index *expObjectTableStorage;
static struct header_complex_index *expValueTableStorage = NULL;
static struct snmp_session session;

/*
 * init_expValueTable():
 *   Initialization routine.  This is called when the agent starts up.
 *   At a minimum, registration of your variables should take place here.
 */
void
init_expValueTable(void)
{
    DEBUGMSGTL(("expValueTable", "initializing...  "));


    /*
     * register ourselves with the agent to handle our mib tree 
     */
    REGISTER_MIB("expValueTable",
                 expValueTable_variables, variable2,
                 expValueTable_variables_oid);

    /*
     * Initialize a "session" that defines who we're going to talk to
     */
    snmp_sess_init(&session);   /* set up defaults */
    session.peername = strdup("localhost");

    DEBUGMSGTL(("expValueTable", "done.\n"));
}

/*
 * mteTriggerTable_add(): adds a structure node to our data set 
 */
static int
expValueTable_add(struct expExpressionTable_data *expression_data,
                  const char *owner, size_t owner_len, const char *name,
                  size_t name_len, oid *index, size_t index_len)
{
    netsnmp_variable_list *vars = NULL;
    struct expValueTable_data *thedata, *StorageTmp;
    struct header_complex_index *hcindex;
    int             found = 0;

    thedata = calloc(1, sizeof(*thedata));
    thedata->expValueCounter32Val = 0;
    thedata->expExpressionOwner = owner;
    thedata->expExpressionOwnerLen = owner_len;
    thedata->expExpressionName = name;
    thedata->expExpressionNameLen = name_len;
    thedata->expValueInstance = index;
    thedata->expValueInstanceLen = index_len;
    thedata->expression_data = expression_data;
    DEBUGMSGTL(("expValueTable", "adding data...  "));
    /*
     * add the index variables to the varbind list, which is 
     * used by header_complex to index the data 
     */


    snmp_varlist_add_variable(&vars, NULL, 0, ASN_OCTET_STR, (const char *) thedata->expExpressionOwner, thedata->expExpressionOwnerLen);     /* expExpressionOwner */
    snmp_varlist_add_variable(&vars, NULL, 0, ASN_OCTET_STR, (const char *) thedata->expExpressionName, thedata->expExpressionNameLen);       /* expExpressionName */
    snmp_varlist_add_variable(&vars, NULL, 0, ASN_PRIV_IMPLIED_OBJECT_ID,
                              (u_char *) thedata->expValueInstance,
                              thedata->expValueInstanceLen * sizeof(oid));

    for (hcindex = expValueTableStorage; hcindex != NULL;
         hcindex = hcindex->next) {
        StorageTmp = (struct expValueTable_data *) hcindex->data;
        if (!strcmp
            (StorageTmp->expExpressionOwner, thedata->expExpressionOwner)
            && (StorageTmp->expExpressionOwnerLen ==
                thedata->expExpressionOwnerLen)
            && !strcmp(StorageTmp->expExpressionName,
                       thedata->expExpressionName)
            && (StorageTmp->expExpressionNameLen ==
                thedata->expExpressionNameLen)
            && !snmp_oid_compare(StorageTmp->expValueInstance,
                                 StorageTmp->expValueInstanceLen,
                                 thedata->expValueInstance,
                                 thedata->expValueInstanceLen)) {
            found = 1;
            break;
        }

    }
    if (!found) {
        header_complex_add_data(&expValueTableStorage, vars, thedata);
        DEBUGMSGTL(("expValueTable", "registered an entry\n"));
    } else {
        SNMP_FREE(index);
        SNMP_FREE(thedata);
        DEBUGMSGTL(("expValueTable",
                    "already have an entry, dont registe\n"));
    }


    DEBUGMSGTL(("expValueTable", "done.\n"));
    return SNMPERR_SUCCESS;
}

static void push(nodelink ** stack, unsigned long value)
{
    nodelink           *newnode;
    newnode = (nodelink *) malloc(sizeof(nodelink));
    if (!newnode) {
        printf("\nMemory allocation failure!");
        return;
    }
    newnode->data = value;
    newnode->next = *stack;
    *stack = newnode;
}

static unsigned long pop(nodelink **stack)
{
    unsigned long   value;
    nodelink       *top;

    if (!*stack)
        return 0;

    top = *stack;
    *stack = (*stack)->next;
    value = top->data;
    free(top);
    return value;
}

static int priority(char operator)
{
    switch (operator) {
    case '*':
    case '/':
        return 4;
    case '+':
    case '-':
        return 3;
    case ')':
        return 2;
    case '(':
        return 1;
    default:
        return 0;
    }
}

static unsigned long calculate(int operator, unsigned long a, unsigned long b)
{
    switch (operator) {
    case '+':
        return (a + b);
    case '-':
        return (a - b);
    case '*':
        return (a * b);
    case '/':
        if (operator == '/' && b == 0) {
            snmp_log(LOG_ERR, "Division by zero attempted\n");
            return 0;
        } else
            return (a / b);
    }
    return 0;
}

static unsigned long get_operand(const char *p, int *length)
{
    char            c[13];
    int             i = 0, k = 1;
    unsigned long   result = 0;

    while (isdigit((unsigned char) *p))
        c[i++] = *(p++);
    *length += --i;
    for (; i >= 0; i--) {
        result += (c[i] - 48) * k;
        k *= 10;
    }
    return result;
}

enum operator_class {
    c_other	= 0,
    c_digit	= 1,
    c_binop	= 2,
    c_rpar	= 3,
    c_lpar	= 4,
};

static int operator_class(char c)
{
    if (isdigit((unsigned char) c))
        return c_digit;
    else if (c == '*' || c == '+' || c == '-' || c == '/')
        return c_binop;
    else if (c == ')')
        return c_rpar;
    else if (c == '(')
        return c_lpar;
    else
        return c_other;
}

static void eval(nodelink **operator, nodelink **operand, char new_op)
{
    unsigned long a, b, op, c;

    DEBUGMSG(("expValueTable", "eval: operator %c; new_op %c\n",
              *operator ? (*operator)->data : '?', new_op));

    while (*operator != NULL &&
           priority(new_op) <= priority((*operator)->data)) {
        b = pop(operand);
        op = pop(operator);
        if (op) {
            a = pop(operand);
            c = calculate(op, a, b);
            DEBUGMSG(("expValueTable", "eval: %ld %c %ld -> %ld\n", a, (char)op,
                      b, c));
            push(operand, c);
        } else {
            DEBUGMSG(("expValueTable", "eval: returning %ld\n", b));
            push(operand, b);
            break;
        }
    }

}

static unsigned long get_result(const char *expr)
{
    int             position = 0;
    unsigned long   a, result = 0;
    const char     *expression;
    nodelink       *operator = NULL;
    nodelink       *operand = NULL;

    expression = expr;
    while (*(expression + position) != '\0'
           && *(expression + position) != '\n') {
        switch (operator_class(*(expression + position))) {
        case c_digit:
            push(&operand, get_operand(expression + position, &position));
            break;
        case c_binop:
            eval(&operator, &operand, *(expression + position));
            push(&operator, *(expression + position));
            break;
        case c_rpar:
            eval(&operator, &operand, ')');
            if (operator->data == '(')
                pop(&operator);
            break;
        case c_lpar:
            push(&operator, '(');
            break;
        default:
            printf("\nInvalid character in expression:");
            a = 0;
            while (*(expression + (int) a) != '\n'
                   && *(expression + (int) a) != '\0') {
                if (a != position)
                    printf("%c", *(expression + (int) a));
                else
                    printf("<%c>", *(expression + (int) a));
                a++;
            }
            return 0;
        }                       /* end switch */
        position++;
    }
    eval(&operator, &operand, ')');
    result = pop(&operand);
    DEBUGMSG(("expValueTable", "%s: %s -> %ld\n", __func__, expr, result));
    return result;
}

static unsigned long Evaluate_Expression(struct expValueTable_data *vtable_data)
{

    struct header_complex_index *hcindex;
    struct expObjectTable_data *objstorage, *objfound;
    struct expValueTable_data *valstorage;
    valstorage = vtable_data;

    const char     *expression;
    char           *result, *resultbak;
    char           *temp, *tempbak;
    char            intchar[10];
    int             i = 0, j, k, l;
    long            value;
    unsigned long   result_u_long;
    temp = malloc(100);
    result = malloc(100);
    tempbak = temp;
    memset(result, 0, 100);
    *result = '\0';
    resultbak = result;

    expression = vtable_data->expression_data->expExpression;

    while (*expression != '\0') {
        if (*expression == '$') {
            objfound = NULL;
            i++;
            for (j = 1; j < 100; j++) {
                if ((*(expression + j) == '+') ||
                    (*(expression + j) == '-') ||
                    (*(expression + j) == '*') ||
                    (*(expression + j) == '/') ||
                    (*(expression + j) == '(') ||
                    (*(expression + j) == ')') ||
                    *(expression + j) == '\0') {
                    break;
                }
            }
            sprintf(temp, "%.*s", j - 1, expression + 1);
            l = atoi(temp);
            expression = expression + j;
            /*
             *   here use snmpget to get value
             */
            for (hcindex = expObjectTableStorage; hcindex != NULL;
                 hcindex = hcindex->next) {
                objstorage = (struct expObjectTable_data *) hcindex->data;
                if (!strcmp
                    (objstorage->expExpressionOwner,
                     valstorage->expExpressionOwner)
                    && (objstorage->expExpressionOwnerLen ==
                        valstorage->expExpressionOwnerLen)
                    && !strcmp(objstorage->expExpressionName,
                               valstorage->expExpressionName)
                    && (objstorage->expExpressionNameLen ==
                        valstorage->expExpressionNameLen)
                    && (l == objstorage->expObjectIndex)) {
                    objfound = objstorage;
                    break;
                }
            }


            if (!objfound) {
                /* have err */
                return 0;
            }
            struct snmp_session *ss;
            struct snmp_pdu *pdu;
            struct snmp_pdu *response;

            oid             anOID[MAX_OID_LEN];
            size_t          anOID_len;

            memcpy(anOID, objfound->expObjectID,
                   objfound->expObjectIDLen * sizeof(oid));
            anOID_len = objfound->expObjectIDLen;
            if (objfound->expObjectIDWildcard == EXPOBJCETIDWILDCARD_TRUE) {
                anOID_len =
                    anOID_len + valstorage->expValueInstanceLen - 2;
                memcpy(anOID + objfound->expObjectIDLen,
                       valstorage->expValueInstance + 2,
                       (valstorage->expValueInstanceLen -
                        2) * sizeof(oid));
            }
            struct variable_list *vars;
            int             status;

            /*
             * Initialize the SNMP library
             */

            /*
             * Initialize a "session" that defines who we're going to talk to
             */
            session.version = vtable_data->expression_data->pdu_version;

            /*
             * set the SNMPv1 community name used for authentication 
             */
            session.community =
                vtable_data->expression_data->pdu_community;
            session.community_len =
                vtable_data->expression_data->pdu_community_len;
            /*
             * Open the session
             */
            SOCK_STARTUP;
            ss = snmp_open(&session);   /* establish the session */

            if (!ss) {
                /* err */
                return 0;
            }
            pdu = snmp_pdu_create(SNMP_MSG_GET);
            snmp_add_null_var(pdu, anOID, anOID_len);

            /*
             * Send the Request out.
             */
            status = snmp_synch_response(ss, pdu, &response);

            /*
             * Process the response.
             */
            if (status == STAT_SUCCESS
                && response->errstat == SNMP_ERR_NOERROR) {
                /*
                 * SUCCESS: Print the result variables
                 */

                vars = response->variables;
                value = *(vars->val.integer);
                sprintf(intchar, "%lu", value);
                for (k = 1; k <= strlen(intchar); k++) {
                    *result = intchar[k - 1];
                    result++;
                }

            } else {
                /*
                 * FAILURE: print what went wrong!
                 */

                if (status == STAT_SUCCESS)
                    fprintf(stderr, "Error in packet\nReason: %s\n",
                            snmp_errstring(response->errstat));
                else
                    snmp_sess_perror("snmpget", ss);

            }

            /*
             * Clean up:
             *  1) free the response.
             *  2) close the session.
             */
            if (response)
                snmp_free_pdu(response);
            snmp_close(ss);

            SOCK_CLEANUP;

        } else {
            *result = *expression;
            result++;
            expression++;
        }
    }
    result_u_long = get_result(resultbak);
    free(tempbak);
    free(resultbak);
    return result_u_long;
}

static void expValueTable_clean(void *data)
{
    struct expValueTable_data *cleanme = data;

    SNMP_FREE(cleanme->expValueInstance);
    SNMP_FREE(cleanme);
}

static void build_valuetable(void)
{
    struct expExpressionTable_data *expstorage;
    struct expObjectTable_data *objstorage, *objfound = NULL;
    struct header_complex_index *hcindex, *object_hcindex;
    const char     *expression;
    oid            *index;
    int             i = 0, j, l;

    DEBUGMSGTL(("expValueTable", "building valuetable...  \n"));

    for (hcindex = expExpressionTableStorage; hcindex != NULL;
         hcindex = hcindex->next) {
        expstorage = (struct expExpressionTable_data *) hcindex->data;
        if (expstorage->expExpressionEntryStatus == RS_ACTIVE) {
            expression = expstorage->expExpression;
            while (*expression != '\0') {
                if (*expression == '$') {
                    i++;
                    for (j = 1; j < 100; j++) {
                        if ((*(expression + j) == '+') ||
                            (*(expression + j) == '-') ||
                            (*(expression + j) == '*') ||
                            (*(expression + j) == '/') ||
                            (*(expression + j) == '(') ||
                            (*(expression + j) == ')') ||
                            *(expression + j) == '\0') {
                            break;
                        }
                    }
                    {
                        char temp[100];

                        sprintf(temp, "%.*s", j - 1, expression + 1);
                        l = atoi(temp);
                    }
                    for (object_hcindex = expObjectTableStorage;
                         object_hcindex != NULL;
                         object_hcindex = object_hcindex->next) {
                        objstorage =
                            (struct expObjectTable_data *) object_hcindex->
                            data;
                        if (!strcmp
                            (objstorage->expExpressionOwner,
                             expstorage->expExpressionOwner)
                            && (objstorage->expExpressionOwnerLen ==
                                expstorage->expExpressionOwnerLen)
                            && !strcmp(objstorage->expExpressionName,
                                       expstorage->expExpressionName)
                            && (objstorage->expExpressionNameLen ==
                                expstorage->expExpressionNameLen)
                            && (l == objstorage->expObjectIndex)) {
                            if (objfound == NULL) {
                                objfound = objstorage;
                            }
                            if (objstorage->expObjectIDWildcard ==
                                EXPOBJCETIDWILDCARD_TRUE)
                                objfound = objstorage;
                        }
                    }
                    expression = expression + j;
                } else {
                    expression++;
                }
            };
        }

        if (!objfound) {
            continue;
        }
        if (objfound->expObjectIDWildcard == EXPOBJCETIDWILDCARD_FALSE) {
            index = calloc(1, MAX_OID_LEN);
            *index = 0;
            *(index + 1) = 0;
            *(index + 2) = 0;
            expValueTable_add(expstorage, objfound->expExpressionOwner,
                              objfound->expExpressionOwnerLen,
                              objfound->expExpressionName,
                              objfound->expExpressionNameLen, index, 3);
        } else {
            oid            *targetOID;
            size_t          taggetOID_len;
            targetOID = objfound->expObjectID;
            struct snmp_pdu *pdu;
            struct snmp_pdu *response;
            oid            *next_OID;
            size_t          next_OID_len;
            taggetOID_len = objfound->expObjectIDLen;
            int             status;
            struct snmp_session *ss;
            /*
             * Initialize the SNMP library
             */


            /*
             * set the SNMP version number 
             */
            session.version = expstorage->pdu_version;

            /*
             * set the SNMPv1 community name used for authentication 
             */
            session.community = expstorage->pdu_community;
            session.community_len = expstorage->pdu_community_len;

            /*
             * Open the session
             */
            SOCK_STARTUP;
            ss = snmp_open(&session);   /* establish the session */
            if (!ss) {
                snmp_perror("ack");
                snmp_log(LOG_ERR, "something horrible happened!!!\n");
                return;
            }

            next_OID = targetOID;
            next_OID_len = taggetOID_len;
            do {
                index = calloc(1, MAX_OID_LEN);
                pdu = snmp_pdu_create(SNMP_MSG_GETNEXT);

                snmp_add_null_var(pdu, next_OID, next_OID_len);

                /*
                 * Send the Request out.
                 */
                status = snmp_synch_response(ss, pdu, &response);

                /*
                 * Process the response.
                 */
                if (status == STAT_SUCCESS
                    && response->errstat == SNMP_ERR_NOERROR) {
                    /*
                     * SUCCESS: Print the result variables
                     */

                    if (((response->variables->type >= SNMP_NOSUCHOBJECT &&
                          response->variables->type <= SNMP_ENDOFMIBVIEW)
                         || snmp_oid_compare(targetOID, taggetOID_len,
                                             response->variables->name,
                                             taggetOID_len) != 0)) {
                        break;
                    }
                    /* add to expValueTable */

                    *index = 0;
                    *(index + 1) = 0;
                    memcpy(index + 2,
                           response->variables->name + taggetOID_len,
                           (response->variables->name_length -
                            taggetOID_len) * sizeof(oid));
                    expValueTable_add(expstorage,
                                      objfound->expExpressionOwner,
                                      objfound->expExpressionOwnerLen,
                                      objfound->expExpressionName,
                                      objfound->expExpressionNameLen,
                                      index,
                                      response->variables->name_length -
                                      taggetOID_len + 2);

                    next_OID = response->variables->name;

                    next_OID_len = response->variables->name_length;




                } else {
                    /*
                     * FAILURE: print what went wrong!
                     */
                    if (status == STAT_SUCCESS)
                        fprintf(stderr, "Error in packet\nReason: %s\n",
                                snmp_errstring(response->errstat));
                    else
                        snmp_sess_perror("snmpget", ss);
                }
            } while (TRUE);

        }

    }

}

static unsigned char *var_expValueTable(struct variable *vp, oid * name,
                                        size_t *length, int exact,
                                        size_t *var_len,
                                        WriteMethod ** write_method)
{
    struct expValueTable_data *StorageTmp = NULL;

    DEBUGMSGTL(("expValueTable", "var_expValueTable: Entering...  \n"));

    /*
     *  before we build valuetable we must free any other valutable if exist
     */
    header_complex_free_all(expValueTableStorage, expValueTable_clean);
    expValueTableStorage = NULL;

    build_valuetable();

    /*
     * this assumes you have registered all your data properly
     */
    if ((StorageTmp =
         header_complex(expValueTableStorage, vp, name, length, exact,
                        var_len, write_method)) == NULL)
        return NULL;


    /*
     * this is where we do the value assignments for the mib results.
     */
    switch (vp->magic) {
        /*
         *   we only support counter32val
         */

    case EXPVALUECOUNTER32VAL:
        StorageTmp->expValueCounter32Val = Evaluate_Expression(StorageTmp);
        *var_len = sizeof(StorageTmp->expValueCounter32Val);
        return (u_char *) & StorageTmp->expValueCounter32Val;

    case EXPVALUEUNSIGNED32VAL:
        /* var_len = sizeof(StorageTmp->expValueUnsigned32Val); */
        /* return (u_char *) & StorageTmp->expValueUnsigned32Val;         */
        return NULL;

    case EXPVALUETIMETICKSVAL:
        /* var_len = sizeof(StorageTmp->expValueTimeTicksVal); */
        /* return (u_char *) & StorageTmp->expValueTimeTicksVal; */
        return NULL;

    case EXPVALUEINTEGER32VAL:
        /* var_len = sizeof(StorageTmp->expValueInteger32Val); */
        /* return (u_char *) & StorageTmp->expValueInteger32Val; */
        return NULL;

    case EXPVALUEIPADDRESSVAL:
        /* var_len = sizeof(StorageTmp->expValueIpAddressVal); */
        /* return (u_char *) & StorageTmp->expValueIpAddressVal; */
        return NULL;

    case EXPVALUEOCTETSTRINGVAL:
        /* var_len = sizeof(StorageTmp->expValueOctetStringVal); */
        /* return (u_char *) & StorageTmp->expValueOctetStringVal;        */
        return NULL;

    case EXPVALUEOIDVAL:
        /* var_len = StorageTmp->expValueOidValLen; */
        /* return (u_char *) & StorageTmp->expValueOidVal; */
        return NULL;

    case EXPVALUECOUNTER64VAL:
        /* var_len = sizeof(StorageTmp->expValueCounter64Val); */
        /* return (u_char *) & StorageTmp->expValueCounter64Val; */
        return NULL;
    default:
        ERROR_MSG("");
	return NULL;
    }
}
