#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

struct HuffmanNode
{
    char data;
    unsigned frequency;
    HuffmanNode *left;
    HuffmanNode *right;

    HuffmanNode(char data, unsigned frequency)
    {
        this->data = data;
        this->frequency = frequency;
        left = right = nullptr;
    }
};

struct Compare
{
    bool operator()(HuffmanNode *a, HuffmanNode *b)
    {
        return a->frequency > b->frequency;
    }
};

void generateHuffmanTable(HuffmanNode *root, string code, unordered_map<char, string> &table)
{
    if (root == nullptr)
        return;

    if (root->data != '$')
    {
        table[root->data] = code;
    }

    generateHuffmanTable(root->left, code + "0", table);
    generateHuffmanTable(root->right, code + "1", table);
}

unordered_map<char, string> getHuffmanTable(char characters[], int frequencies[], int n)
{
    unordered_map<char, unsigned> freqMap;
    for (int i = 0; i < n; ++i)
    {
        freqMap[characters[i]] = frequencies[i];
    }

    priority_queue<HuffmanNode *, vector<HuffmanNode *>, Compare> pq;

    for (auto &pair : freqMap)
    {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    while (pq.size() > 1)
    {
        HuffmanNode *left = pq.top();
        pq.pop();
        HuffmanNode *right = pq.top();
        pq.pop();

        HuffmanNode *newNode = new HuffmanNode('$', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    HuffmanNode *root = pq.top();

    unordered_map<char, string> huffmanTable;
    generateHuffmanTable(root, "", huffmanTable);

    return huffmanTable;
}

int main()
{
    char characters[] = {'a', 'b', 'c', 'd', 'e'};
    int frequencies[] = {25, 20, 15, 10, 30};
    int n = sizeof(characters) / sizeof(characters[0]);

    unordered_map<char, string> huffmanTable = getHuffmanTable(characters, frequencies, n);

    cout << "Huffman Table:\n";
    for (auto &pair : huffmanTable)
    {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}