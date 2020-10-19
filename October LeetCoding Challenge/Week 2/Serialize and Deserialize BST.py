# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root: TreeNode) -> str:
        """Encodes a tree to a single string.
        """
        if root:
            return str(root.val) + "." + str(self.serialize(root.left)) + str(self.serialize(root.right))
        return ""
            
        

    def deserialize(self, data: str) -> TreeNode:
        """Decodes your encoded data to tree.
        """
        vertexes = deque([int(vertex) for vertex in data.split(".") if vertex])

        def build(left_value, right_value):
            if vertexes and left_value < vertexes[0] < right_value:
                vertex = vertexes.popleft()
                return TreeNode(vertex, build(left_value, vertex), build(vertex, right_value))

        return build(-1, 10000)
        

# Your Codec object will be instantiated and called as such:
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# tree = ser.serialize(root)
# ans = deser.deserialize(tree)
# return ans
