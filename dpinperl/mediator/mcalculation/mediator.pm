##
 * mediator.pm
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
package mediator;
sub new {
my ($class,$multiplier,$divider,$subtracter,$adder)=@_;
my $ref=bless {MULTIPLIER=>$multiplier,DIVIDER=>$divider,SUBTRACTER=>$subtracter,ADDER=>$adder},$class;
map{$_->mediator($ref)} ($multiplier,$divider,$subtracter,$adder);
$ref;
}
sub informmultiplier {
my ($ref,$expression)=@_;
$ref->{SUBTRACTER}->evaluate($expression);
}
sub informdivider {
my ($ref,$expression)=@_;
$ref->{MULTIPLIER}->evaluate($expression);
}
sub informsubtracter {
my ($ref,$expression)=@_;
$ref->{ADDER}->evaluate($expression);
}
sub informadder {
my ($ref,$expression)=@_;
$expression;
}
sub evaluate {
my ($ref,$expression)=@_;
print "expression:",$expression,"\n";
$ref->{DIVIDER}->evaluate($expression);
}
1;
