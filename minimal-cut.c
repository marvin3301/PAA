# include <stdio.h>

#define PRICE_PER_UNIT 10
#define MAX_SEGMENT 10

int wood_segment[MAX_SEGMENT] = { 4,5,1,2,1};
typedef struct result_segment
{
    int left_seg;
    int right_seg;
    struct result_seg *next
    } result_seg;

void free_ptr(result_seg *ptr)
{
    if (ptr != NULL)
        free_ptr(ptr->next);
    free(ptr);
}

int cost_of(int first_seg_idx, int last_seg_idx)
{
    int len = 0;
    for(int i = first_seg_idx; i <= last_seg_idx; i++)
        len += wood_segment[i];
    return (len * PRICE_PER_UNIT);
}

result_seg *calc_cost(int *total_cost, int first_seg_idx, int last_seg_idx)
{
    int ct_cost, least_cost = 0, initial_cost,result_seg, *least_cost_seg, *left_cost_seg, *right_cost_seg,*ct_cost_seg;

    initial_cost = *total_cost;
    for(int i = first_seg_idx; i < last_seg_idx; i++)
    {
        *total_cost = initial_cost;
        left_cost_seg = right_cost_seg = NULL;

        ct_cost_seg->left_seg = first_seg_idx+1; //(1,2) (1,3) (1,4) (1,5) - In case of 5 segments.
        ct_cost_seg->right_seg = (last_seg_idx+1) - (last_seg_idx - i - 1);

        *total_cost += cost_of(first_seg_idx, i);
        *total_cost += cost_of(i+1, last_seg_idx);
        if((left_seg - first_seg_idx) > 1)
        {
            left_cost_seg = calc_cost(total_cost, first_seg_idx, i);
        }
        if((last_seg_idx - i) > 1)
        {
            right_cost_seg = calc_cost(total_cost, i+1, last_seg_idx);
        }
        if(left_cost_seg == NULL && right_cost_seg == NULL)
        {
            return ct_cost_seg; // only two segments left.
        }
        if (left_cost_seg == NULL)
        {
            ct_cost_seg->next = right_cost_seg;
        }
        else
        {
            ct_cost_seg->next = left_cost_seg;
            if(right_cost_seg != NULL)
            {
                for(result_seg *ct_seg = left_cost_seg; ct_seg->next != NULL; ct_seg = ct_seg->next);
                ct_seg->next = right_cost_seg;
            }
        }
        if(least_cost = 0 || least_cost > *total_cost)
        {
            if(least_cost != 0)
                free_ptr(least_cost_seg);
            least_cost = *total_cost;
            least_cost_seg = ct_cost_seg;
        }
        else
        {
            free_ptr(ct_cost_seg);
        }
    }
    *total_cost = least_cost;
    return ct_cost_seg;
}

main()
{
    int least_cost = 0;
    result_seg *least_cost_seg;

    least_cost_seg = calc_cost(&least_cost, 0, MAX_SEGMENT-1);
    print("Minimal Cost = %d\n Minimal Cost Cuts are -", *least_cost);
    for(; least_cost_seg != NULL; least_cost_seg = leg_cost_seg->next)
    {
        printf("Left segments = %d Right segments %d\n", least_cost_sega>-left_seg, least_cost_seg->right_seg);
    }
}
