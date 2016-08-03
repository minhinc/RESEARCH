##
 * user.pm
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
package user;
use base qw(handler person);
sub new {
my ($class,$person,$entertime,$enterfloor,$exitfloor)=@_;
$class->SUPER::new({person=>$person,entertime=>$entertime,enterfloor=>$enterfloor,exitfloor=>$exitfloor});
}
sub execute {
my $ref=shift;
my $canenter=0;
if(defined $ref->{entertime}) {
if($ref->{enterfloor}>$ref->{exitfloor}) {
$ref->{person}->getlift()->bttn($ref->{enterfloor},2) if $ref->{person}->getlift()->isopen()!=$ref->{enterfloor};
}else {
$ref->{person}->getlift()->bttn($ref->{enterfloor},1) if $ref->{person}->getlift()->isopen()!=$ref->{enterfloor};
}
$ref->{entertime}=undef;
}
if(!defined $ref->{entertime}) {
if(defined $ref->{exitfloor} && !defined $ref->{enterfloor} && $ref->{person}->getlift()->isopen()==$ref->{exitfloor}) {
$ref->{person}->getlift()->gtinout(1,$ref);
$ref->{exitfloor}=undef;
}else {
if(defined $ref->{enterfloor} && $ref->{person}->getlift()->isopen()==$ref->{enterfloor}) {
if($ref->{exitfloor}>$ref->{enterfloor}) {
if(!($ref->{person}->getlift()->{BUTTON}[$ref->{enterfloor}]&1)) {
$canenter=1;
}
}else {
if(!($ref->{person}->getlift()->{BUTTON}[$ref->{enterfloor}]&2)) {
$canenter=1;
}
}
if($canenter) {
$ref->{person}->getlift()->gtinout(2,$ref);
$ref->{person}->getlift()->bttn($ref->{exitfloor},4);
$ref->{enterfloor}=undef;
}
}
}
}
}
1;
