##
 * basedec.pm
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
package basedec;
sub new {
my $class=shift;
bless {ID=>$class},$class;
}
sub id {
my $ref=shift;
$ref->{ID};
}
sub execute {
my ($ref,$expression)=@_;
print $ref->id,":executing expression:",$expression->getexpression,"\n";
my $expressionstring=$expression->getexpression;
while($expressionstring=~/(-?\d+)($ref->{operator})(-?\d+)/) {
$expressionstring=join('',$`,eval "$1$2$3",$');
}
$expression->setexpression($expressionstring);
}
sub accept {
my ($ref,$visitor,$expression)=@_;
$visitor->visit($ref,$expression);
}
1;
