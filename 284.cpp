// disc | T: O(1) | S: O(1) 

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.

        _hasNext = Iterator::hasNext();
        if (_hasNext) _next = Iterator::next();
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() { return _next; }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int dummy = _next;

        _hasNext = Iterator::hasNext();
        if (_hasNext) _next = Iterator::next();
        
        return dummy;
    }

    bool hasNext() const { return _hasNext; }

private:
    int _next;
    bool _hasNext;
};
