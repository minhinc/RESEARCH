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
use terminalexpression;
use orexpression;
use andexpression;

my $expressionref=new andexpression(new terminalexpression('RAHUL'),new orexpression(new terminalexpression('ABDUL'),new andexpression(new orexpression(new terminalexpression('RAVI'),new terminalexpression('JOHN')),new terminalexpression('UDONG'))));
print "grammar:RAHUL AND (ABDUL OR ((RAVI OR JOHN) AND UDONG))\n";
print "interpreting 'JOHN AND UDONG AND RAHUL':",$expressionref->interpret('JOHN AND UDONG AND RAHUL'),"\n";
print "interpreting 'RAHUL AND RAVI':",$expressionref->interpret('RAHUL AND RAVI');
