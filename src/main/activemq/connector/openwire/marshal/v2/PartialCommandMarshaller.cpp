/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <activemq/connector/openwire/marshal/v2/PartialCommandMarshaller.h>

#include <activemq/connector/openwire/commands/PartialCommand.h>

//
//     NOTE!: This file is autogenerated - do not modify!
//            if you need to make a change, please see the Java Classes in the
//            activemq-core module
//

using namespace std;
using namespace activemq;
using namespace activemq::io;
using namespace activemq::connector;
using namespace activemq::connector::openwire;
using namespace activemq::connector::openwire::commands;
using namespace activemq::connector::openwire::marshal;
using namespace activemq::connector::openwire::utils;
using namespace activemq::connector::openwire::marshal::v2;

///////////////////////////////////////////////////////////////////////////////
DataStructure* PartialCommandMarshaller::createObject() const {
    return new PartialCommand();
}

///////////////////////////////////////////////////////////////////////////////
unsigned char PartialCommandMarshaller::getDataStructureType() const {
    return PartialCommand::ID_PARTIALCOMMAND;
}

///////////////////////////////////////////////////////////////////////////////
void PartialCommandMarshaller::tightUnmarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataInputStream* dataIn, BooleanStream* bs ) throw( io::IOException ) {

    BaseDataStreamMarshaller::tightUnmarshal( wireFormat, dataStructure, dataIn, bs );

    PartialCommand* info =
        dynamic_cast<PartialCommand*>( dataStructure );
    info->setCommandId( dataIn->readInt() );
    info->setData( tightUnmarshalByteArray( dataIn, bs ) );
}

///////////////////////////////////////////////////////////////////////////////
int PartialCommandMarshaller::tightMarshal1( OpenWireFormat* wireFormat, DataStructure* dataStructure, BooleanStream* bs ) throw( io::IOException ) {

    PartialCommand* info =
        dynamic_cast<PartialCommand*>( dataStructure );

    int rc = BaseDataStreamMarshaller::tightMarshal1( wireFormat, dataStructure, bs );
    bs->writeBoolean( info->getData().size() != 0 );
    rc += (int)(info->getData().size() == 0 ? 0 : info->getData().size() + 4);

    return rc + 4;
}

///////////////////////////////////////////////////////////////////////////////
void PartialCommandMarshaller::tightMarshal2( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataOutputStream* dataOut, BooleanStream* bs ) throw( io::IOException ) {

    BaseDataStreamMarshaller::tightMarshal2( wireFormat, dataStructure, dataOut, bs );

    PartialCommand* info =
        dynamic_cast<PartialCommand*>( dataStructure );
    dataOut->write( info->getCommandId() );
    if( bs->readBoolean() ) {
        dataOut->write( (int)info->getData().size() );
        dataOut->write( &info->getData()[0], info->getData().size() );
    }
}

///////////////////////////////////////////////////////////////////////////////
void PartialCommandMarshaller::looseUnmarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataInputStream* dataIn ) throw( io::IOException ) {

    BaseDataStreamMarshaller::looseUnmarshal( wireFormat, dataStructure, dataIn );
    PartialCommand* info = 
        dynamic_cast<PartialCommand*>( dataStructure );
    info->setCommandId( dataIn->readInt() );
    info->setData( looseUnmarshalByteArray( dataIn ) );
}

///////////////////////////////////////////////////////////////////////////////
void PartialCommandMarshaller::looseMarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataOutputStream* dataOut ) throw( io::IOException ) {

    PartialCommand* info =
        dynamic_cast<PartialCommand*>( dataStructure );
    BaseDataStreamMarshaller::looseMarshal( wireFormat, dataStructure, dataOut );

    dataOut->write( info->getCommandId() );
    dataOut->write( info->getData().size() != 0 );
    if( info->getData().size() != 0 ) {
        dataOut->write( (int)info->getData().size() );
        dataOut->write( &info->getData()[0], info->getData().size() );
    }
}

