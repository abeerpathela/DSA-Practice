import java.util.*;

class LFUCache {

    class Node {
        int key, value, freq;
        Node prev, next;

        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;
        }
    }

    class DLL {
        Node head, tail;
        int size;

        DLL() {
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head.next = tail;
            tail.prev = head;
            size = 0;
        }

        void add(Node node) {
            node.next = head.next;
            node.prev = head;
            head.next.prev = node;
            head.next = node;
            size++;
        }

        void remove(Node node) {
            node.prev.next = node.next;
            node.next.prev = node.prev;
            size--;
        }

        Node removeLast() {
            if (size > 0) {
                Node node = tail.prev;
                remove(node);
                return node;
            }
            return null;
        }
    }

    private int capacity;
    private int minFreq;
    private Map<Integer, Node> keyMap;
    private Map<Integer, DLL> freqMap;

    public LFUCache(int capacity) {
        this.capacity = capacity;
        this.minFreq = 0;
        keyMap = new HashMap<>();
        freqMap = new HashMap<>();
    }

    public int get(int key) {
        if (!keyMap.containsKey(key)) return -1;

        Node node = keyMap.get(key);
        update(node);
        return node.value;
    }

    public void put(int key, int value) {
        if (capacity == 0) return;

        if (keyMap.containsKey(key)) {
            Node node = keyMap.get(key);
            node.value = value;
            update(node);
        } else {
            if (keyMap.size() == capacity) {
                DLL minList = freqMap.get(minFreq);
                Node toRemove = minList.removeLast();
                keyMap.remove(toRemove.key);
            }

            Node newNode = new Node(key, value);
            minFreq = 1;

            DLL list = freqMap.getOrDefault(1, new DLL());
            list.add(newNode);
            freqMap.put(1, list);

            keyMap.put(key, newNode);
        }
    }

    private void update(Node node) {
        int freq = node.freq;
        DLL list = freqMap.get(freq);
        list.remove(node);

        if (freq == minFreq && list.size == 0) {
            minFreq++;
        }

        node.freq++;

        DLL newList = freqMap.getOrDefault(node.freq, new DLL());
        newList.add(node);
        freqMap.put(node.freq, newList);
    }
}