//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

network ARQ3
{
    parameters: 
       double prob;
   submodules:
        source3: Source3 {
            @display("p=67,80");
        }
        dest3: Dest3 {
            @display("p=205,79");
        }
    connections:
        source3.out --> {delay = 20 ms; ber = prob;} --> dest3.in;
        dest3.out --> source3.in;
}
