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

use memento;
use adder;
my $adderref=new adder;
my $caretaker=new memento;
print "result:",$adderref->add(10,20),"\n";;
print "result:",$adderref->add(20,30),"\n";
$adderref->backup($caretaker);
print "result:",$adderref->add(1000,20),"\n";
$adderref->backup($caretaker);
print "result:",$adderref->add(420,-20),"\n";
$adderref->backup($caretaker);
$adderref->add(10,-100000000);
$adderref->restore($caretaker->get);
print "result:",$adderref->add;
