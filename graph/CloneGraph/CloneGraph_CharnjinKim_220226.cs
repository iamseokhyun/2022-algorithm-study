public class Solution 
{
    Dictionary<int, Node> nodemap = new Dictionary<int, Node>();
    public Node CloneGraph(Node node) {
        if (node==null) {
            return null;
        }
        if (!nodemap.ContainsKey(node.val)) {
            nodemap[node.val]= new Node(node.val, new List<Node>());
            foreach (var neighbor in node.neighbors) {
                nodemap[node.val].neighbors.Add(CloneGraph(neighbor)); 
            }
        }
        return nodemap[node.val];
    }
}