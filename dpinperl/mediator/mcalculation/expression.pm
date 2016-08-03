##
 * expression.pm
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
package expression;
sub new {
my ($class,$operator)=@_;
bless {operator=>$operator},$class;
}
sub mediator {
my ($ref,$mediator)=@_;
$ref->{MEDIATOR}=$mediator;
}
sub evaluate {
my ($ref,$expression)=@_;
while($expression=~/(-?\d+)($ref->{operator})(-?\d+)/) {
$expression=join('',$`,eval "$1$2$3",$');
}
$expression;
}
1;
