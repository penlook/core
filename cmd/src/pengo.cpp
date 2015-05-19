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

#include "cli/handler.hpp"
#include "cli/cli.hpp"

int main(int argc, char *argv[]) {
	handler cmd;
	cli pengo;
	
	pengo.name("pengo")
	  	 .add<string>("new",   (callback) cmd.create, 'n',   "Create application", false, "")
	  	 .add<string>("build", (callback) cmd.build,  'b',  "Build and install application", false)
	  	 .add<string>("test",  (callback) cmd.test,   't',   "Test application", false, "unit",
		 		oneof<string>(
					 "unit", 
					 "benchmark"
				)
		 )
		 .add("run",  (callback) cmd.run, '\0', "Run application under hot-code reload")
	  	 .add("help", (callback) cmd.help,  0,   "Show pengo help")
	  	 .parse(argc, argv);

	if (argc==1 || !pengo.valid()) {
		cerr << pengo.error() << endl << pengo.usage();
		return 0;
	}
	
	pengo.run();	
	return 0;
}