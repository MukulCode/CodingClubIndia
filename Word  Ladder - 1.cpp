/*Problem Link: https://leetcode.com/problems/word-ladder/description/



Problem Description:
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words
 beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation
sequence from beginWord to endWord, or 0 if no such sequence exists.



Approach:

We can assume each word to be a node in a graph where edges are the single character transformations which are connecting the before and
after transformation words. Our problem then boils down to finding the shortest path from Source Node(beginWord)--> Destination Node(endWord)

We will make use BFS approach as DFS can lead to exponential time complexity in case of graphs for finding shortest paths because there is a possibility
of having two or more choices choosing a node whereas in cans of BFS we would be moving breadth wise instead of exploring an entire path recursiively
Thus it will lead to polynomial time complexity

We first insert all the words in a set for purpose of avoiding an already visited word.
1. Push the begin word in queue
2. While the queue is not empty explore all the words present at a particular level by transfroming each character of a popped out word from
 the queue by replacing it with every letter from a to z
3. If any of the transformed word matched with the queue return the current level as it would be the number of transformations done
4. If the word is present in the set then push it to the queue because we made a transformation and remove it from set(as it is visited). Alsp once particular character has
been transformed from a to z replacer it back with its original character so that it does not disturb the transformations of further characters.
If not then continue
5. if we did not return while traversing the queue the return 0
Using this algorithm we can implement all the functionalities of Queue using stacks.


Level count is the significance of the number of transformations beacuse we are adding to the queue only when there is a match and that is leading to increse in level
There would only be certain instances where the time complexity would go O(n) for ceratin operations. Most of the operations would be O(1). Thus we say it is amortised time complexity



Time Complexity:  O(n*n*w*26) // n is the length of the word and w is the total number of words in the dictionary
Explanation: We are transforming each character of a word  26 times so n*26 then we are comparing each transformed string with the target
string so n*26*n and we are performing all these steps for all the w words in the dictionary  so n*n*w*26

Space Complexity: O(2n) Queue + Unordered Set




Implementation in C++:

**/

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {

        queue<string> q;

        q.push(beginWord);

        unordered_set<string> words;

        for (auto e : wordList)
        {

            words.insert(e);
        }

        if (words.find(endWord) == words.end())
        {
            return 0;
        }

        int len = 0;

        while (!q.empty())
        {

            len++;

            int qlen = q.size();

            for (int i = 0; i < qlen; i++)
            {

                string s = q.front();

                q.pop();

                for (int j = 0; j < s.length(); j++)
                {

                    char c = s[j];

                    for (char x = 'a'; x <= 'z'; x++)
                    {

                        s[j] = x;

                        if (s == endWord)
                        {
                            return len + 1;
                        }

                        if (words.find(s) == words.end())
                        {
                            continue;
                        }

                        words.erase(s);
                        q.push(s);
                    }

                    s[j] = c;
                }
            }
        }

        return 0;
    }
};