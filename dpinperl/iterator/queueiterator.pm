##
 * queueiterator.pm
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
package queueiterator;
use base qw(iterator);
sub new {
my $class=shift;
my $ref=$class->SUPER::new;
($ref->{SEGMENTSIZE},$ref->{CURRENTSEGMENTBEGIN},$ref->{CURRENTSEGMENTEND},$ref->{SEGMENTINDEX},$ref->{SEGMENTCOUNT},$ref->{SEGMENT})=(5,0,-1,-1,0,[0]);
$ref;
}
sub getfirst {
my $ref=shift;
$ref->{SEGMENTINDEX}=$ref->{CURRENTSEGMENTBEGIN};
${$ref->{AGGREGATE}}[$ref->{INDEX}=$ref->{BEGIN}];
}
sub getnext {
my $ref=shift;
if(!(($ref->{INDEX}+1)%($ref->{SEGMENTSIZE}))) {
++$ref->{SEGMENTINDEX};
$ref->{INDEX}=${$ref->{SEGMENT}}[$ref->{SEGMENTINDEX}]*$ref->{SEGMENTSIZE};
--$ref->{INDEX};
}
${$ref->{AGGREGATE}}[++$ref->{INDEX}];
}
sub additem {
my ($ref,$item)=@_;
print "adding to queue:",$item,"\n";
if(!(($ref->{END}+1)%($ref->{SEGMENTSIZE}))) {
++$ref->{CURRENTSEGMENTEND};
${$ref->{SEGMENT}}[$ref->{CURRENTSEGMENTEND}]=$ref->{CURRENTSEGMENTEND} if !defined ${$ref->{SEGMENT}}[$ref->{CURRENTSEGMENTEND}];
$ref->{END}=${$ref->{SEGMENT}}[$ref->{CURRENTSEGMENTEND}]*$ref->{SEGMENTSIZE}-1;
}
${$ref->{AGGREGATE}}[++$ref->{END}]=$item;
}
sub removeitem {
my $ref=shift;
if(!(($ref->{BEGIN}+1)%($ref->{SEGMENTSIZE}))) {
++$ref->{CURRENTSEGMENTBEGIN};
$ref->{BEGIN}=${$ref->{SEGMENT}}[$ref->{CURRNTSEGMENTBEGIN}]*$ref->{SEGMENTSIZE};
my $i=0;
while($i!=$ref->{SEGMENTCOUNT}) {
${$ref->{SEGMENT}}[$i]+=${$ref->{SEGMENT}}[$i+1];
${$ref->{SEGMENT}}[$i+1]=${$ref->{SEGMENT}}[$i]-${$ref->{SEGMENT}}[$i+1];
${$ref->{SEGMENT}}[$i]-=${$ref->{SEGMEN}}[$i+1];
++$i;
}
$ref->{CURRENTSEGMENTEND}-=1;
$ref->{CURRENTSEGMENTBEGIN}-=1;
}else {
++$ref->{BEGIN};
}
}
sub end {
my $ref=shift;
($ref->{END} < $ref->{INDEX})?1:0;
}
1;
