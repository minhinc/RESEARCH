##
 * state.pm
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
package state;
my ($addition,$subtraction,$multiplication,$division,$result)=undef;
sub additionstate {
$addition=new('addition') if !defined $addition;
$addition;
}
sub subtractionstate {
$subtraction=new('subtraction') if !defined $subtraction;
$subtraction;
}
sub multiplicationstate {
$multiplication=new('multiplication') if !defined $multiplication;
$multiplication;
}
sub divisionstate {
$division=new('division') if !defined $division;
$division;
}
sub result {
$result=new('result') if !defined $result;
$result;
}
sub new {
my $class=shift;
bless {},$class;
}

sub calculate {
my ($ref,$expression,$operator,$calculatorref)=@_;
while($expression=~/(-?\d+)($operator)(-?\d+)/) {
$calculatorref->printonscreen("$1:$3\n");
$expression=join('',$`,eval "$1$2$3",$');
}
$expression;
}
1;
