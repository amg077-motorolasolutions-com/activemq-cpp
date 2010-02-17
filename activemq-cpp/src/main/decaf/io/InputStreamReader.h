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

#ifndef _DECAF_IO_INPUTSTREAMREADER_H_
#define _DECAF_IO_INPUTSTREAMREADER_H_

#include <decaf/util/Config.h>
#include <decaf/io/Reader.h>

namespace decaf {
namespace io {

    class InputStream;

    /**
     * An InputStreamReader is a bridge from byte streams to character streams.
     *
     * For top efficiency, consider wrapping an InputStreamReader within a BufferedReader.
     * For example:
     *
     *   BufferedReader* in
     *       = new BufferedReader( new InputStreamReader( System.in, false ), true );
     *
     * @see OutputStreamWriter
     *
     * @since 1.0
     */
    class DECAF_API InputStreamReader : public Reader {
    private:

        // The target InputStream
        InputStream* stream;

        // Does this instance own the InputStream
        bool own;

        // Has the reader been closed.
        bool closed;

    public:

        /**
         * Create a new InputStreamReader that wraps the given InputStream.
         *
         * @param stream
         *      The InputStream to read from. (cannot be null).
         * @param own
         *      Does this object own the passed InputStream (defaults to false).
         *
         * @throw NullPointerException if the passed InputStream is NULL.
         */
        InputStreamReader( InputStream* stream, bool own = false );

        virtual ~InputStreamReader();

        virtual void close() throw( decaf::io::IOException );

        virtual int read( char* buffer, std::size_t offset, std::size_t count )
            throw( IOException, lang::exceptions::NullPointerException );

        virtual bool ready() const throw( decaf::io::IOException );

        virtual int read( std::vector<char>& buffer )
            throw( decaf::io::IOException );

        virtual int read() throw( decaf::io::IOException );

        virtual int read( decaf::nio::CharBuffer* charBuffer )
                 throw( decaf::io::IOException,
                        decaf::lang::exceptions::NullPointerException,
                        decaf::nio::ReadOnlyBufferException );

    protected:

        virtual void checkClosed() const throw( decaf::io::IOException );

    };

}}

#endif /* _DECAF_IO_INPUTSTREAMREADER_H_ */