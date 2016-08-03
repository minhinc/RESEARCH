##
 * adder.pm
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
package adder;
sub new {
my ($class,$firstnumber,$secondnumber)=@_;
bless {FIRSTNUMBER=>$firstnumber,SECONDNUMBER=>$secondnumber},$class;
}
sub add {
my $ref=shift;
print "originator(adder)::add firstnumber,secondnumber:",$_[0],":",$_[1],"\n" if scalar @_;
print "originaator(adder)::add firstnumber,secondnumber:",$ref->{FIRSTNUMBER},":",$ref->{SECONDNUMBER},"\n" if !scalar @_;
(scalar @_)?($ref->{FIRSTNUMBER}=shift)+($ref->{SECONDNUMBER}=shift):$ref->{FIRSTNUMBER}+$ref->{SECONDNUMBER};
}
sub backup {
my ($ref,$caretaker)=@_;
print "originator(adder)::backup firstnumber,secondnumber:",$ref->{FIRSTNUMBER},":",$ref->{SECONDNUMBER},"\n";
$caretaker->save($ref->{FIRSTNUMBER},$ref->{SECONDNUMBER});
}
sub restore {
my ($ref,$caretaker)=@_;
print "orgininator(adder)::restore firstnumber,secondnumber:",$caretaker->firstnumber,":",$caretaker->secondnumber,"\n";
($ref->{FIRSTNUMBER},$ref->{SECONDNUMBER})=($caretaker->firstnumber,$caretaker->secondnumber);
}
1;
