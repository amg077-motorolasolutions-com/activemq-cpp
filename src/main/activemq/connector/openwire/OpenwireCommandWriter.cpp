/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
#include "OpenwireCommandWriter.h"

using namespace std;
using namespace activemq;
using namespace activemq::connector;
using namespace activemq::connector::openwire;
using namespace activemq::transport;
using namespace activemq::io;
using namespace activemq::exceptions;

////////////////////////////////////////////////////////////////////////////////
OpenwireCommandWriter::OpenwireCommandWriter(void)
{
    outputStream = NULL;
}

////////////////////////////////////////////////////////////////////////////////
OpenwireCommandWriter::OpenwireCommandWriter( OutputStream* os )
{
    outputStream = os;
}

////////////////////////////////////////////////////////////////////////////////
void OpenwireCommandWriter::writeCommand( Command* command ) 
    throw ( transport::CommandIOException )
{
    try
    {
        if( outputStream == NULL )
        {
            throw CommandIOException( 
                __FILE__, __LINE__, 
                "OpenwireCommandWriter::writeCommand - "
                "output stream is NULL" );
        }

        // TODO
    }
    AMQ_CATCH_RETHROW( CommandIOException )
    AMQ_CATCH_EXCEPTION_CONVERT( ActiveMQException, CommandIOException )
    AMQ_CATCHALL_THROW( CommandIOException )
}

////////////////////////////////////////////////////////////////////////////////
void OpenwireCommandWriter::write( const unsigned char* buffer, size_t count ) 
    throw( IOException )
{
    if( outputStream == NULL )
    {
        throw IOException( 
            __FILE__, __LINE__, 
            "OpenwireCommandWriter::write(char*,int) - input stream is NULL" );
    }

    outputStream->write( buffer, count );
}
 
////////////////////////////////////////////////////////////////////////////////
void OpenwireCommandWriter::writeByte( unsigned char v ) throw( IOException )
{
    if( outputStream == NULL )
    {
        throw IOException( 
            __FILE__, __LINE__, 
            "OpenwireCommandWriter::write(char) - input stream is NULL" );
    }
   
    outputStream->write( v );
}


