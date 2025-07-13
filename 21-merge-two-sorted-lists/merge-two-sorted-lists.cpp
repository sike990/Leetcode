/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* fir, ListNode *sec , ListNode* ans){
        if(fir == nullptr && sec == nullptr){
            // while(fir != nullptr){
            //     ListNode* nex = new ListNode(fir->val);
            //     ans -> next = nex;
            //     fir = fir -> next;
            // }
            // while(sec != nullptr){
            //     ListNode* nex = new ListNode(sec->val);
            //     ans -> next = nex;
            //     sec = sec -> next;
            // }
            return ans;
        }
        ListNode* left = (fir == NULL)?new ListNode(INT_MAX) : fir;
        ListNode* rig = (sec == NULL)?new ListNode(INT_MAX) : sec;
        
        if(left->val <= rig->val){
            ans -> next = new ListNode(left->val);
            fir = fir -> next;
        }
        else{
            ans -> next = new ListNode(rig->val);
            sec = sec -> next;
        }
        return merge(fir , sec , ans);
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*  ans = new ListNode(-1);
        //ListNode* ans = merge(list1 , list2 , temp);
        ListNode*  temp = ans;
        ListNode* fir = list1;
        ListNode* sec = list2;
        while(fir != nullptr && sec != nullptr){
            ListNode* topush = nullptr;
            if(fir->val <= sec -> val){
                topush = new ListNode(fir -> val);
                fir  = fir->next;
            }
            else{
                topush = new ListNode(sec -> val);
                sec =  sec->next;
            }
            temp -> next = topush;
            temp = topush;
        }
        while(sec != nullptr){
            ListNode* topush = new ListNode(sec -> val);
            temp -> next = topush;
            temp = topush;
            sec = sec->next;
        }
        while(fir != nullptr){
            ListNode* topush = new ListNode(fir -> val);
            temp -> next = topush;
            temp = topush;
            fir = fir->next;
        }
        return ans->next;
    }
};