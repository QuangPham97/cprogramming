#include "types.h"
#include "ylib.h"

typedef struct _rrm_du_config_udate_node_t
{
    YLNODE          node;
    UInt16          transaction_id;
    UInt8           num_impacted_cell;
    UInt8           num_response_recv;
}rrm_du_config_udate_node_t;

YLIST du_config_udp_list;


int main(int argc, char const *argv[])
{
    ylInit(&du_config_udp_list);
    int i = 0;
    for(i = 0; i < 10; i++)
    {
        rrm_du_config_udate_node_t *p_du_config_update = (rrm_du_config_udate_node_t *)malloc(sizeof(rrm_du_config_udate_node_t));
        p_du_config_update->num_impacted_cell = i*3;
        p_du_config_update->num_response_recv = i*2;
        p_du_config_update->transaction_id = i;
        
        if(i%2 == 0)
        {
            ylPushHead(&du_config_udp_list, &p_du_config_update->node);
        }else       
        {
            ylPushTail(&du_config_udp_list, &p_du_config_update->node);
        }
        if(i == 5)
        {
            /*Inset Node Befor node index 5*/
            rrm_du_config_udate_node_t *p_du_config_update_insert = (rrm_du_config_udate_node_t *)malloc(sizeof(rrm_du_config_udate_node_t));
            ylInsertNodeBefor(&du_config_udp_list, &p_du_config_update->node, &p_du_config_update_insert->node);
        }
        printf("Address node insert: %p - %p - size: %lu\n", &p_du_config_update->node, p_du_config_update, sizeof(rrm_du_config_udate_node_t));
    }

    rrm_du_config_udate_node_t *p_du_config_update_node = NULL;
    p_du_config_update_node = (rrm_du_config_udate_node_t *)ylFirst(&du_config_udp_list);
    printf("Fist node: %p\n", p_du_config_update_node);
    while (p_du_config_update_node)
    {
        printf("Node: %p\n", p_du_config_update_node);
        printf("transaction_id: %d\n", p_du_config_update_node->transaction_id);
        p_du_config_update_node = (rrm_du_config_udate_node_t *)ylNext(&p_du_config_update_node->node);
    }
    UInt32 count = ylCount(&du_config_udp_list);
    printf("Count: %u\n",count);
    return 0;
}
