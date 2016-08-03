##
 * memento.pm
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
package memento;
use base qw(caretaker);
sub new {
my ($class,$firstnumber,$secondnumber)=@_;
bless {FIRSTNUMBER=>$firstnumber,SECONDNUMBER=>$secondnumber},$class;
}
sub firstnumber {
my $ref=shift;
(scalar @_)?$ref->{FIRSTNUMBER}=shift:$ref->{FIRSTNUMBER};
}
sub secondnumber {
my $ref=shift;
(scalar @_)?$ref->{FIRSTNUMBER}=shift:$ref->{SECONDNUMBER};
}
sub save {
my ($ref,$firstnumber,$secondnumber)=@_;
my $mementoref=$ref->caretaker->getnext;
if(!defined $ref->{FIRSTNUMBER}) {
($ref->{FIRSTNUMBER},$ref->{SECONDNUMBER})=($firstnumber,$secondnumber);
if(!defined $mementoref) {
$ref->caretaker->push($ref);
}else {
$ref->caretaker->push($mementoref);
}}else {
if(!defined $mementoref) {
$ref->caretaker->push(__PACKAGE__->new($firstnumber,$secondnumber));
}else {
$mementoref->firstnumber($firstnumber);
$mementoref->secondnumber($secondnumber);
}
}
}
sub previous {
my $ref=shift;
$ref->caretaker->getprevious;
}
sub get {
my $ref=shift;
$ref->caretaker->SUPER::get;
}
1;
