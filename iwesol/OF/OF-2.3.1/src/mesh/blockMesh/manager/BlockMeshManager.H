/*---------------------------------------------------------------------------*\
                               |
  _____        _______ ____    | IWESOL: IWES Open Library
 |_ _\ \      / / ____/ ___|   |
  | | \ \ /\ / /|  _| \___ \   | Copyright: Fraunhofer Institute for Wind
  | |  \ V  V / | |___ ___) |  | Energy and Energy System Technology IWES
 |___|  \_/\_/  |_____|____/   |
                               | http://www.iwes.fraunhofer.de
                               |
-------------------------------------------------------------------------------
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright  held by original author
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of IWESOL and it is based on OpenFOAM.

    IWESOL and OpenFOAM are free software: you can redistribute them and/or modify
    them under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    IWESOL and OpenFOAM are distributed in the hope that they will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::oldev::BlockMeshManager

Description

SourceFiles
    BlockMeshManager.C

\*---------------------------------------------------------------------------*/

#ifndef BlockMeshManager_H
#define BlockMeshManager_H

#include "BlockMeshCreator.H"
#include "PointLinePath.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

namespace oldev
{


/*---------------------------------------------------------------------------*\
                         Class BlockMeshManager Declaration
\*---------------------------------------------------------------------------*/

class BlockMeshManager
:
    public BlockMeshCreator
{
    // Private Member Functions

        /// Disallow default bitwise copy construct
        BlockMeshManager(const BlockMeshManager&);

        /// Disallow default bitwise assignment
        void operator=(const BlockMeshManager&);


public:

    // Constructors

        /// Construct from components
        BlockMeshManager
        (
        		const Time & runTime
        );


    // Member Functions

        // Access

    	/// set a spline that goes along several blocks. nBlokMax < 0 means all
    	void setInterBlockSpline(
    			const pointField & splinep,
    			label iStartBlock,
    			label faceToNextBlock,
    			label iSpline,
    			label nBlockMax = -1
    		);


    	/** set a spline that goes along several blocks, with start and end
    	 * deltaA and deltaB. nBlokMax < 0 means all
    	 */
    	void setInterBlockSpline(
    			const Foam::vector & deltaA,
    			const Foam::vector & deltaB,
    			label iStartBlock,
    			label faceToNextBlock,
    			label iSpline,
    			label nBlockMax = -1,
    			const scalarList & sList = scalarList()
    		);

    	/// returns the list of s values of all points and in a block line
    	scalarList getBlockLineSList(
    			label iStartBlock,
    			label iSpline,
    			label face,
    			label nBlockMax = -1,
    			bool withFirst = true,
    			bool withLast = true
    			) const ;

    	/// returns inter block line path
    	PointLinePath getInterBlockPath(
    			label iStartBlock,
    			label iSpline,
    			label face,
    			label nBlockMax = -1,
    			bool withFirst = true,
    			bool withLast = true
    			) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace oldev

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
