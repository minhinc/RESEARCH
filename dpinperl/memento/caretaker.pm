##
 * caretaker.pm
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
package caretaker;
my $caretakerref=undef;
sub caretaker {
$caretakerref=__PACKAGE__->new if !defined $caretakerref;
$caretakerref;
}
sub new {
my $class=shift;
bless {MEMENTOSTACK=>undef,TOP=>-1,INDEX=>-1,MAXCOUNT=>5},$class;
}
sub getnext {
my $ref=shift;
${$ref->{MEMENTOSTACK}}[($ref->{TOP}+1)%($ref->{MAXCOUNT})];
}
sub get {
my $ref=shift;
${$ref->{MEMENTOSTACK}}[$ref->{INDEX}=$ref->{TOP}];
}
sub push {
my ($ref,$value)=@_;
print "caretaker,adding memento to queue",$value->{FIRSTNUMBER},":",$value->{SECONDNUMBER},"\n";
${$ref->{MEMENTOSTACK}}[$ref->{INDEX}=$ref->{TOP}=($ref->{TOP}+1)%($ref->{MAXCOUNT})]=$value;
}
sub getprevious {
my $ref=shift;
${$ref->{MEMENTOSTACK}}[($ref->{INDEX}==0)?$ref->{INDEX}=$ref->{MAXCOUNT}-1:--$ref->{INDEX}];
}
1;
