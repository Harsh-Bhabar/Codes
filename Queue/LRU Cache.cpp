class DLL
{
public:
	DLL *next;
	DLL *prev;
	int key, val;
	DLL(int key, int val)
	{
		this->key = key;
		this->val = val;
	}
};

class LRUCache
{
public:
	DLL *head = new DLL(0, 0);
	DLL *tail = new DLL(0, 0);
	int cap;
	unordered_map<int, DLL *> mp;

	LRUCache(int capacity)
	{
		cap = capacity;
		head->next = tail;
		tail->prev = head;
	}

	// adds a node to the front
	void addNodeToFront(DLL *newNode)
	{
		DLL *temp = head->next;
		head->next = newNode;
		newNode->prev = head;
		newNode->next = temp;
		temp->prev = newNode;
	}

	// deletes a node and attach its neighbors
	void eraseNode(DLL *delNode)
	{
		DLL *delNext = delNode->next;
		DLL *delPrev = delNode->prev;
		delNext->prev = delPrev;
		delPrev->next = delNext;
	}

	int get(int key)
	{
		if (mp.find(key) != mp.end())
		{
			DLL *resNode = mp[key];
			int ans = resNode->val;
			mp.erase(key);			 // erase from the map
			eraseNode(resNode);		 // erase from the exsing list
			addNodeToFront(resNode); // add new ele to front
			mp[key] = head->next;	 // updated the node addess in map
			return ans;
		}
		else
		{
			return -1;
		}
	}

	void put(int key, int value)
	{
		if (mp.find(key) != mp.end())
		{
			DLL *node = mp[key];
			mp.erase(key);	 // erase from the map
			eraseNode(node); // erase from the list
		}
		if (mp.size() == cap)
		{
			mp.erase(tail->prev->key); // erase from map
			eraseNode(tail->prev);	   // erase from list
		}
		addNodeToFront(new DLL(key, value));
		mp[key] = head->next;
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */