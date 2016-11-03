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

int main(int intargc, char * argv[])
{
    leveldb::DB *db;
    leveldb::Options options;
    
    options.create_if_missing = true;
    
    std::string dbpath = "blog";
    
    leveldb::Status status = leveldb::DB::Open( options, dbpath,&db );
    
    assert ( status.ok() );
    
    std::string email_key = "email:jankuo";
    std::string email_value = "llh110220@gmail.com";
    
    std::cout << "open db ok! " << std::endl;
    
    std::string value;
    leveldb::Status sta;
    
    sta = db->Put( leveldb::WriteOptions(), email_key, email_value );
    if ( sta.ok() )
    {
        std::cout << "put email_key" << email_key << " ok " << std::endl;
    }
    
    sta = db->Get( leveldb::ReadOptions(), email_key, &value );
    if ( sta.ok() )
    {
        std::cout << "get email_key:" << email_key << " ok " << std::endl;
        std::cout << email_key << ":" << value << std::endl;
    }
    
    delete db;
    return 0;
}
