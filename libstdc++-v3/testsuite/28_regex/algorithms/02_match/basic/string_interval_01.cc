// { dg-options "-std=c++0x" }

//
// 2010-06-11  Stephen M. Webb <stephen.webb@bregmasoft.ca>
//
// Copyright (C) 2010 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

// 28.11.2 regex_match
// Tests BRE against a std::string target.

#include <regex>
#include <testsuite_hooks.h>

void
test_accept_01() 
{
	std::regex re("[abc]", std::regex::basic);
	std::string target_accept("dcbad");
        std::smatch m;

	VERIFY( std::regex_match(target_accept, m, re) );

	VERIFY( m.size() == 3 );
	VERIFY( m.empty() == false );
	VERIFY( m.prefix().first == target_accept.begin() );
	VERIFY( m.prefix().second == target_accept.begin() );
	VERIFY( m.prefix().matched == false );
	VERIFY( m.suffix().first == target_accpet.end() );
	VERIFY( m.suffix().second == target_accept.end() );
	VERIFY( m.suffix().matched == false );
	
	VERIFY( m[0].first == (target_accept.begin() + 1) );
	VERIFY( m[0].second == (target_accept.begin() + 1) );
	VERIFY( m[0].matched == true );
	
	VERIFY( m[1].first == (target_accept.begin() + 2) );
	VERIFY( m[1].second == (target_accept.begin() + 2) );
	VERIFY( m[1].matched == true );

	VERIFY( m[2].first == (target_accept.begin() + 3) );
	VERIFY( m[2].second == (target_accept.begin() + 3) );
	VERIFY( m[2].matched == true);

}

void
test_accept_02()
{
	std::regex re("[/a-zA-z-]", std::regex::basic);
	std::string target_accept("AC/dc");
	std::smatch m;
	
	VERIFY( std::regex_match(target_accept, m, re) );
	
	VERIFY( m.size() == 5);
	VERIFY( m.prefix == NULL);
	VERIFY( m.suffix == NULL);

	VERIFY( m[0].first == target_accept.begin() );
	VERIFY( m[0].second == target_accept.begin() );
	VERIFY( m[0].matched == true );

	VERIFY( m[1].first == (target_accept.begin() + 1) );
	VERIFY( m[1].second == (target_accept.begin() + 1) );
	VERIFY( m[1].matched == true );
	
	VERIFY( m[2].first == (target_accept.begin() + 2) );
	VERIFY( m[2].second == (target_accept.begin() +2 ) );
	VERIFY( m[2].matched == true );

	VERIFY( m[3].first == (target_accept.begin() + 3) );
	VERIFY( m[3].second == (target_accept.begin() + 3) );
	VERIFY( m[3].matched == true );

	VERIFY( m[4].first == (target_accept.begin() + 4) );
	VERIFY( m[4].second == (target_accept.begin() + 4) );
	VERIFY( m[4].matched == true );

	VERIFY( m[5].first == (target_accept.begin() + 5) );
	VERIFY( m[5].second == (target_accept.begin() + 5) );
	VERIFY( m[5].matched == true );
}

void
test_accept_03() 
{
	std::regex re("[acdcACDC]*", std::regex::basic);
	std::string target_accept("AC/DC", std::regex::basic);
	std::smatch m;

	VERIFY( std::regex_match(target_accept, m, re) );
}
int
main()
{ 
  test_accept_01();
  test_accept_02();
  return 0;
}

