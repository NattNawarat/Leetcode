class Trie {
    private Map<Character,Trie> leaf;
    private boolean endOfWord;
    public Trie() {
        this.leaf = new HashMap<>();
        this.endOfWord = false;
    }

    public void insert(String word) {
        System.out.println("insert");
        addLeaf(this,word, 0);
    }

    public boolean search(String word) {
        System.out.println("search");
        Trie endNode = travel(this,word,0);
        if (endNode == null){
            return false;
        }
        return endNode.endOfWord;
    }

    public boolean startsWith(String prefix) {
        System.out.println("startWith");
        Trie endNode = travel(this,prefix,0);
        return endNode != null;
    }

    private Trie travel(Trie currentNode, String word, int charIndex){
        if (charIndex == word.length()){
            return currentNode;
        } else {
            char currentCharacter = word.charAt(charIndex);
            System.out.println(currentCharacter);
            if(!currentNode.leaf.containsKey(currentCharacter)){
                return null;
            }
            return travel(currentNode.leaf.get(currentCharacter),word,charIndex+1);
        }


    }

    private void addLeaf(Trie currentNode, String word, int charIndex){
        if (charIndex == word.length()){
            currentNode.endOfWord = true;
            return;
        }
        char currentCharacter = word.charAt(charIndex);
        if(!currentNode.leaf.containsKey(currentCharacter)){
            System.out.print("add ");
            currentNode.leaf.put(currentCharacter, new Trie());
        }
        System.out.println(currentCharacter);
        addLeaf(currentNode.leaf.get(currentCharacter), word, charIndex + 1);
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */