##
 * calculator.pm
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
package calculator;
use subtracter;
use adder;
use multiplier;
use divider;
sub new {
my $class=shift;
bless {SUBTRACTER=>new subtracter,ADDER=>new adder,MULTIPLIER=>new multiplier,DIVIDER=>new divider}, $class;
}
sub compute {
my ($ref, $expressionstring)=@_;
my ($operand1, $operand2);
if ($expressionstring=~/(.+)\+(.*)/) {
$operand1=$1;
$operand2=$2;
$ref->{ADDER}->compute($ref->compute($operand1),$ref->compute($operand2));
} elsif ($expressionstring=~/(.+)\-(.*)/) {
$operand1=$1;
$operand2=$2;
$ref->{SUBTRACTER}->compute($ref->compute($operand1),$ref->compute($operand2));
} elsif ($expressionstring=~/(.+)\*(.*)/) {
$operand1=$1;
$operand2=$2;
$ref->{MULTIPLIER}->compute($ref->compute($operand1),$ref->compute($operand2));
} elsif ($expressionstring=~/(.+)\/(.*)/) {
$operand1=$1;
$operand2=$2;
$ref->{DIVIDER}->compute($ref->compute($operand1),$ref->compute($operand2));
} else {
$expressionstring=~s/[ ]*([0-9]+)[ ]*/\1/;
$expressionstring;
}
}
1; 
