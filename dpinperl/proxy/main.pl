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
use writedatabaseproxy;
use readonlydatabaseproxy;
my $wrdtbsproxyref=new writedatabaseproxy;
my $rddtbsproxyref=new readonlydatabaseproxy;
$wrdtbsproxyref->addtable("one",[[1,2,3],[4,5,6],[7,8,9]]);
$wrdtbsproxyref->addtable("two",[['a','b','c'],['d','e','f'],['g','h','i'],['j','k','l']]);
print "table size for tableid \"one\" : ",$rddtbsproxyref->gettablesize("one"),"\n";
print "table data for tableid \"one\" :\n";
map {print @{$_}, "\n"} @{$rddtbsproxyref->gettable("one")};
print "table size for tableid \"two\" : ",$rddtbsproxyref->gettablesize("two"),"\n";
print "table data for tableid \"two\" :\n";
map {print @{$_},"\n"} @{$rddtbsproxyref->gettable("two")};
