##
 * subject.pm
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
package subject;
use sharedmem;
use base qw(handler);
sub new {
my ($class,$expression)=@_;
'sharedmem'->instance->setinindex(2,$expression);
'sharedmem'->instance->setinindex(1,0);
bless [],$class;
}
sub execute {
my $ref=shift;
if('sharedmem'->instance->getfromindex(1)==1) {
print "result:",'sharedmem'->instance->getfromindex(2);
"stop";
}else {
'sharedmem'->instance->setinindex(1,1);
'sharedmem'->instance->setinindex(0,'sharedmem'->instance->getfromindex(2));
map {$_->notify} @$ref;
}
}
sub register {
my ($ref,@item)=@_;
push @$ref,@item;
}
1;
