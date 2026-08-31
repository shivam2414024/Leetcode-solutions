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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* temp = head;
        vector<int> vec;
        int count = 1;
        while (temp != nullptr) {
            if (prev && temp->next) {
                if ((prev->val < temp->val && temp->val > temp->next->val) ||
                    (prev->val > temp->val && temp->val < temp->next->val))
                    vec.push_back(count);
            }
            count++;
            prev = temp;
            temp = temp->next;
        }
        int minDist = INT_MAX;
        int maxDist = INT_MIN;

        if (!vec.empty() && vec.size() >= 2)
            maxDist = vec[vec.size() - 1] - vec[0];

        for (int i = 1; i < vec.size(); i++) {
            minDist = min(minDist, vec[i] - vec[i - 1]);
        }

        if (minDist == INT_MAX && maxDist == INT_MIN)
            return {-1, -1};
        return {minDist, maxDist};
    }
};