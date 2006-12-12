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

#ifndef _ACTIVEMQ_CONNECTOR_STOMP_COMMANDS_TEXTMESSAGECOMMAND_H_
#define _ACTIVEMQ_CONNECTOR_STOMP_COMMANDS_TEXTMESSAGECOMMAND_H_

#include <cms/TextMessage.h>
#include <activemq/connector/stomp/commands/StompMessage.h>
#include <activemq/connector/stomp/commands/CommandConstants.h>
#include <string.h>

namespace activemq{
namespace connector{
namespace stomp{
namespace commands{

    class TextMessageCommand : public StompMessage< cms::TextMessage >
    {
    public:

        TextMessageCommand() :
            StompMessage< cms::TextMessage >() {
                initialize( getFrame() );
        }
        
        TextMessageCommand( StompFrame* frame ) : 
            StompMessage< cms::TextMessage >( frame ) {
                validate( getFrame() );
        }
        
    	virtual ~TextMessageCommand() {}

        /**
         * Clonse this message exactly, returns a new instance that the
         * caller is required to delete.
         * @return new copy of this message
         */
        virtual cms::Message* clone() const {
            StompFrame* frame = getFrame().clone();
            
            return new TextMessageCommand( frame );
        }   

        /**
         * Gets the message character buffer.
         * @return The message character buffer.
         */
        virtual std::string getText() const throw( cms::CMSException ) {
            
            const std::vector<unsigned char>& bytes = getBytes();
            if( bytes.size() == 0 ){
                return "";
            }
            
            return std::string( (char*)&bytes[0] );
        }
        
        /**
         * Sets the message contents.
         * @param msg The message buffer.
         */
        virtual void setText( const char* msg ) throw( cms::CMSException ) {
            setBytes( (unsigned char*)msg, strlen(msg) + 1, false );
        }

        /**
         * Sets the message contents.
         * @param msg The message buffer.
         */
        virtual void setText( const std::string& msg ) throw( cms::CMSException ) {
            setBytes( (unsigned char*)msg.c_str(), msg.length() + 1, false );
        }

    };

}}}}

#endif /*_ACTIVEMQ_CONNECTOR_STOMP_COMMANDS_TEXTMESSAGECOMMAND_H_*/
