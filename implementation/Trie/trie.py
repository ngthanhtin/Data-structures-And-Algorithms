ALPHABET_SIZE = 26
# Trie node
class TrieNode:    
    def __init__(self):
        # isLeaf is true if the node represents
        # end of a word
        self.countLeaf = 0
        self.children = [None for i in range(ALPHABET_SIZE)]

def insert(root_node, key):
    length = len(key)
    
    temp = root_node
    for level in range(length):
        index = ord(key[level]) - ord('a')
        if (temp.children[index] == None):
            temp.children[index] = TrieNode()
         
        temp = temp.children[index]
         
    # mark last node as leaf
    temp.countLeaf += 1
 
# Function to find a word
def find(root_node, key):
    length = len(key)
    temp = root_node
    
    for level in range(length):
        index = ord(key[level]) - ord('a')
        if temp.children[index] == None:
#             return False, level - 1
            return False
        temp = temp.children[index]
    
#     return temp.countLeaf > 0, length - 1
     return temp.countLeaf > 0

# class Solution:
#     def indexPairs(self, text: str, words: List[str]) -> List[List[int]]:
#         # Construct Tries
#         length = len(text)
#         roots = [TrieNode() for i in range(length)]
#         for i in range(length):
#             sub_text = text[i:]
#             insert(roots[i], sub_text)
        
#         answer_list = []
#         for word in words:
#             for i, root in enumerate(roots):
#                 contain, level = find(root, word)
#                 if level == len(word) - 1:
#                     answer_list.append([i, i + level])
        
#         answer_list.sort(key=lambda x: (x[0],x[1]))
#         return answer_list
    



