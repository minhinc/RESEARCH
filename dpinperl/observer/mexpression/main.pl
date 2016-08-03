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

use adder;
use multiplier;
use divider;
use subtracter;
use subject;
use scheduler;

my $adderref=new adder;
my $multiplierref=new multiplier;
my $dividerref=new divider;
my $subtracterref=new subtracter;

my $subjectref=new subject("1-2+4*3-6/2+8*3-2*70/10");
$subjectref->register($adderref,$multiplierref,$dividerref,$subtracterref);
new scheduler($subjectref,$adderref,$multiplierref,$dividerref,$subtracterref)->start;
