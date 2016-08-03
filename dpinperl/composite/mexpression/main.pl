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
use expression;
use adder;
use subtracter;
use divider;
use multiplier;

my $expressionref=new expression(new divider, new expression(new multiplier, new expression(new subtracter, new expression(new adder))));
printf "evaluation expression:%s\n",q(1+3/3*2-2+6/2/3-2);
my $result=$expressionref->compute('1+3/3*2-2+6/2/3-2');
printf "result:%d\n",$result;
printf "evaluation expression:%s\n",q(1-2+4*3-6/2+8*3-2*70/10);
$result=$expressionref->compute(q(1-2+4*3-6/2+8*3-2*70/10));
printf "result:%d",$result;
