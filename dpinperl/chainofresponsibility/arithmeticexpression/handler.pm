##
 * handler.pm
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
package handler;
sub new {
my ($class,$operator)=@_;
bless {OPERATOR=>$operator}, $class;
}
sub next {
my $ref=shift;
if (scalar @_) {
$ref->{NEXT}=shift;
}
$ref->{NEXT};
}
sub handle {
my ($ref,$expression)=@_;
print "expression:",$expression,"\n";
while($expression=~/(.*?)([-]?\d+)[$ref->{OPERATOR}]([-]?\d+)(.*)/) {
$expression=join("",$1,eval qq($2 $ref->{OPERATOR} $3), $4);
}
if(defined $ref->next) {
$ref->next->handle($expression);
} else {
$expression;
}
}
1;
