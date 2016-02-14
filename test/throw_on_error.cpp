// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/core/lightweight_test.hpp>

#include <boost/process.hpp>
#include <boost/system/system_error.hpp>

namespace bp = boost::process;
namespace bpi = boost::process::initializers;

int main(int argc, char* argv[])
{
    bool thrown = false;
    try {
        bp::execute(
            bpi::cmd="doesnt-exist",
            bpi::throw_on_error
        );
        thrown = false;
    }
    catch(boost::system::system_error & )
    {
        thrown = true;
    }
    BOOST_TEST(thrown);
    return boost::report_errors();
}

