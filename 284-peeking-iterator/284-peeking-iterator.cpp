class PeekingIterator : public Iterator {
    
private:
    int cache;
    bool cached;
	
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        cache = 0;
        cached = false;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(cached) return cache;
        cache = this->Iterator::next();
        cached = true;
        return cache;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        if(cached){
            cached = false;
            return cache;
        }
        return this->Iterator::next();
	}
	
	bool hasNext() const {
	    return cached || this->Iterator::hasNext();
	}

};