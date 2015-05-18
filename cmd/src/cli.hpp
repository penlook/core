/**
 * Pengo Project
 *
 * Copyright (c) 2015 Penlook Development Team
 *
 * --------------------------------------------------------------------
 *
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License
 * as published by the Free Software Foundation, either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public
 * License along with this program.
 * If not, see <http://www.gnu.org/licenses/>.
 *
 * --------------------------------------------------------------------
 *
 * Author:
 *     Loi Nguyen       <loint@penlook.com>
 */

#include <library/cmdline.hpp> 
#include <functional>
#include <iostream>
#include <map>

using namespace std;

namespace pengo {
class cli {

  private:
  	cmdline::parser cmd;
    map<string, function<string(string)>> callback;
    bool is_valid;

  public:
	cli &add(
           const string &name,
           char  short_name = 0,
           const string &desc = "",
           const function<string(string)> &func) {
        callback[name] = func;
        cmd.add(name, short_name, desc);
        return *this;
    }

  	template <class T>
  	cli &add(
           const string &name,
           char  short_name=0,
           const string &desc ="",
           const T def = T(),
           const function<string(string)> &func) {
        callback[name] = func;
        cmd.add<T>(name, short_name, desc, need, def);
        return *this;
  	}

  	template <class T, class F>
  	cli &add(
           const string &name,
           char  short_name = 0,
           const string &desc = "",
           bool  need = true,
           const T def = T(),
           F reader = F(),
           const function<string(string)> &func) {
        callback[name] = func;
        cmd.add<T, F>(name, short_name, desc, need, def, reader);
        return *this;
	}
    
    cli &name(const string &name) {
        cmd.set_program_name(name);
        return *this;
    }
  
    cli &parse(int argc, const char * const argv[]) {
        is_valid = cmd.parse(argc, argv);
        return *this;
    }
    
    bool valid() {
        return is_valid;
    }
    
    string error() const {
        return cmd.error();
    }
    
    string usage() const {
        return cmd.usage();
    }
    
    int size() {
        return cmd.rest().size();
    }
    
    void run() {
        cout << "Run console"; 
    }
};
}