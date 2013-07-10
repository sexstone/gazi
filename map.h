#ifndef _map_h_
#define _map_h_

#include <stdio.h>
#include <map>

namespace gazi { namespace inner {


struct compare{
    bool operator()( const char* s1, const char* s2 ) const{
        return strcmp( s1, s2 ) < 0;
    }
};

template<typename K ,typename V , typename J = std::map<K,V,compare>>
class map {

public:
	map():map_(new J()){}
	~map(){delete map_;}

	void Delete(){
		delete this ;
	}

	void erase(K key){
		typename J::iterator  iter = map_->find(key);
		if (iter != map_->end()) { 
			map_->erase(key);
		} 
	}

	void insert(K  key, V value){
		erase(key);
		map_->insert(typename J::value_type(key ,value)) ;
	}

	V find( K  key){
		typename J::iterator  iter = map_->find(key);
		if (iter != map_->end()) { 
			 return  iter->second ; 
		} else { 
			return NULL;
		}
	}
	
	bool empty(){
		return map_->empty();
	}

	void clear(){
		return map_->clear();
	}

	int size(){
		return static_cast<int>(map_->size());
	}

private :
	J*  map_;
};

}}

#endif