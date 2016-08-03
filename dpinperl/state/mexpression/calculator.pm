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
use result;
use addition;
use division;
use multiplication;
use subtraction;
sub new {
my ($class,$state)=@_;
bless {STATE=>$state},$class;
}
sub setstate {
my ($ref,$state)=@_;
$ref->{STATE}=$state;
}
sub calculate {
my ($ref,$expression)=@_;
my $state=$ref->{STATE};
$ref->{STATE}->calculate($expression,$ref);
while($state != $ref->{STATE}) {
$expression=$ref->{STATE}->calculate($expression,$ref);
}
$expression;
}
sub printonscreen {
my ($ref,$string)=@_;
print $string;
}
1;
