##
 * main.pl
 # Design Patterns in Perl
 # Copyright (c) 2015-2016 Minh Inc www.minhinc.com
 #
 # This file is part of DesignPatternsInPerl
 #
 # DesignPatternsInPerl
 # modify it under the terms of the GNU Lesser General Public
 # License as published by the Free Software Foundation; either
 # version 2.1 of the License, or (at your option) any later version.
 #
 # DesignPatternsInPerl
 # but WITHOUT ANY WARRANTY; without even the implied warranty of
 # MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 # Lesser General Public License for more details.
 #
 # You should have received a copy of the GNU Lesser General Public
 # License along with Mgmp; if not, write to the Free Software
 # Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
##
use strict;
use warnings;

use city;
use buisnesstype;
use buisnessman;
use statistics;
new buisnessman("person : tim",new buisnesstype("buisnesstype : hardware",new city("city : mangalore"),new city("city : mysore"),new city("city : mandya")),new buisnesstype("buisnesstype : software",new city("city : chennai"),new city("city : chaibasa"),new city("city : churu")),new buisnesstype("buisnesstype : realstate",new city("city : delhi"),new city("city : dhaka"),new city("city : dumka")))->accept(new statistics);
