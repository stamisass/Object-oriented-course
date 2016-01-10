
#include <iostream>

#pragma once

template<class T>
class SharedPointer {
	T* ob;
	int* refcount;
	bool shareable;

	int refdown() {
		return --(*refcount);
	}

	int refup() {
		return ++(*refcount);
	}

	void markUnshareable() {
		shareable = false;
	}


public:

	virtual ~SharedPointer() {
		if(refdown() == 0) {
			delete ob;
		}

		if(getRefcount() <= 0) {
			delete refcount;
		}
	}



	SharedPointer():shareable(true) {
		ob = NULL;
		refcount = new int(0);
	}



	SharedPointer(T *pointee):shareable(true) {
		ob = pointee;
		refcount = new int(1);
	}



	SharedPointer(const SharedPointer& sp) {
		
		ob = sp.ob;
		refcount = sp.refcount;
		refup();
	}



	SharedPointer operator=(const SharedPointer& sp) {
		if (this == &sp) {
			return *this;
		}


		if(refdown() == 0) {
			delete ob;
		}

		if(getRefcount() <= 0) {
			delete refcount;
		}

		ob = sp.ob;
		refcount = sp.refcount;
		refup();

		return *this;
	}



	bool operator==(const SharedPointer& sp) {
		return ob == sp.ob;
	}


	
	T* operator->() const {
		return ob;
	}



	T& operator*() const {
		return *ob;
	}


	void setOb(T pointee) {
		if(getRefcount() == 0 && ob == NULL) {
			ob = new T(pointee);
			refup();
		}
	}


	const T& getOb() const {
		return *ob;
	}


	int getRefcount() {
		return *refcount;
	}



	bool isShareable() {
		return shareable;
	}



	bool isShared() {
		return *refcount < 1;
	}



};