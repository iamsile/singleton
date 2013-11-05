//
//  main.cpp
//  singleton
//
//  Created by taowei on 13-11-5.
//  Copyright (c) 2013年 taowei. All rights reserved.
//

#include <iostream>
using namespace std;

class singleton_t {
public:
	static singleton_t *instance() {
		if (p_instance_ == 0) {
			static singleton_t instance;
			p_instance_ = &instance;
		}
		return p_instance_;
	}
	void count_increase() {
		cnt++;
	}
	int count() const {
		return cnt;
	}
private:
	singleton_t():cnt(0) {}
	~singleton_t() {}
	static singleton_t *p_instance_;
	int cnt;
};

class singleton {
public:
	static singleton *instance() {
		if (p_instance_ == 0) {
			static singleton instance;
			p_instance_ = &instance;
		}
		return p_instance_;
	}
private:
	singleton() {
		singleton_t::instance()->count_increase();
	}
	~singleton() {}
	static singleton *p_instance_;
};

singleton *singleton::p_instance_ = 0;
singleton_t *singleton_t::p_instance_ = 0;

int main(int argc, const char * argv[])
{
	singleton_t::instance();
	cout << "---" << singleton_t::instance()->count()<< endl;
    return 0;
}

