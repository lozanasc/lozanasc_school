public class trees {
            Node root;
            class Node {
                int data;
                Node left, right;
                Node(int value){
                    this.data = value;
                    left = right = null;
                }
            }
            // Constructors
            trees(int item){
                root = new Node(item);
            }
            trees(){
                root = null;
            }
        public static void main(String[] args) {
            
        }
}