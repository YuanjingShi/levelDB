//
//  main.cpp
//  levedDB
//
//  Created by Isaac Shi on 11/3/16.
//  Copyright © 2016 Issac Shi. All rights reserved.
//

#include <iostream>
#include <cassert>
#include "leveldb/db.h"
//it is supposed to be some comments
int main(int intargc, char * argv[])
{
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;
    std::string dbpath = "testdb";
    leveldb::Status status = leveldb::DB::Open (options, dbpath, &db);
    assert (status.ok ());
    std::string key = "test";
    std::string val = "test_value";
    s = db->Put (leveldb::WriteOptions (), key, val);
    val.clear ();
    s = db->Get (leveldb::ReadOptions (), key, &val);
    
    std::cout << key << ": " << val << std::endl;
}
