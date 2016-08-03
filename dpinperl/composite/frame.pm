##
 * frame.pm
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
package frame;
use base qw(shape);
sub new {
my ($class, $frameid)=@_;
my $ref=$class->SUPER::new;
push @$ref, $frameid;
$ref;
}
sub draw {
my $ref=shift;
print "---\n";
printf "frame::draw, frameid:%s\n",${$ref}[0];
foreach my $child(@{$ref}[1..$#{$ref}]) {
$child->draw();
}
print "---\n";
}
sub add {
my ($ref, @childref)=@_;
push @$ref, @childref;
}
sub remove {
my ($ref, $childref)=@_;
delete @$ref[(grep{${$ref}[$_]=~/$childref/} 0..$#{$ref})];
}
1;
