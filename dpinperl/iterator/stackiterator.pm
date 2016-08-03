##
 * stackiterator.pm
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
package stackiterator;
use base qw(iterator);
sub getfirst {
my $ref=shift;
${$ref->{AGGREGATE}}[$ref->{INDEX}=$ref->{END}];
}
sub getnext {
my $ref=shift;
${$ref->{AGGREGATE}}[--$ref->{INDEX}];
}
sub end {
my $ref=shift;
($ref->{INDEX} < $ref->{BEGIN})?1:0;
}
sub additem {
my ($ref,$item)=@_;
print "adding to stack:",$item,"\n";
push @{$ref->{AGGREGATE}}, $item;
$ref->{END}+=1;
}
sub removeitem {
my $ref->shift;
print "removing from stack:",${$ref->{AGGREGATE}}[$ref->{END}],"\n";
--$ref->{END};
}
1;
