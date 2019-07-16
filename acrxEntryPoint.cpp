// (C) Copyright 2002-2012 by Autodesk, Inc. 
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted, 
// provided that the above copyright notice appears in all copies and 
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting 
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS. 
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK, INC. 
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to 
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable.
//

//-----------------------------------------------------------------------------
//----- acrxEntryPoint.cpp
//-----------------------------------------------------------------------------
#include "StdAfx.h"
#include "resource.h"
#include "adslib.h"
#include "aced.h"
#include "gemat3d.h"
#include <vector>

//-----------------------------------------------------------------------------
#define szRDS _RXST("")

//-----------------------------------------------------------------------------
//----- ObjectARX EntryPoint
class CArxProject5App : public AcRxArxApp {

public:
	CArxProject5App() : AcRxArxApp() {}

	virtual AcRx::AppRetCode On_kInitAppMsg(void *pkt) {
		// TODO: Load dependencies here

		// You *must* call On_kInitAppMsg here
		AcRx::AppRetCode retCode = AcRxArxApp::On_kInitAppMsg(pkt);

		// TODO: Add your initialization code here

		return (retCode);
	}

	virtual AcRx::AppRetCode On_kUnloadAppMsg(void *pkt) {
		// TODO: Add your code here

		// You *must* call On_kUnloadAppMsg here
		AcRx::AppRetCode retCode = AcRxArxApp::On_kUnloadAppMsg(pkt);

		// TODO: Unload dependencies here

		return (retCode);
	}

	virtual void RegisterServerComponents() {
	}

	// The ACED_ARXCOMMAND_ENTRY_AUTO macro can be applied to any static member 
	// function of the CArxProject5App class.
	// The function should take no arguments and return nothing.
	//
	// NOTE: ACED_ARXCOMMAND_ENTRY_AUTO has overloads where you can provide resourceid and
	// have arguments to define context and command mechanism.

	// ACED_ARXCOMMAND_ENTRY_AUTO(classname, group, globCmd, locCmd, cmdFlags, UIContext)
	// ACED_ARXCOMMAND_ENTRYBYID_AUTO(classname, group, globCmd, locCmdId, cmdFlags, UIContext)
	// only differs that it creates a localized name using a string in the resource file
	//   locCmdId - resource ID for localized command

	// Modal Command with localized name
	// ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject5App, MyGroup, MyCommand, MyCommandLocal, ACRX_CMD_MODAL)
	static void MyGroupMyCommand() {
		// Put your command code here

	}

	// Modal Command with pickfirst selection
	// ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject5App, MyGroup, MyPickFirst, MyPickFirstLocal, ACRX_CMD_MODAL | ACRX_CMD_USEPICKSET)
	static void MyGroupMyPickFirst() {
		ads_name result;
		int iRet = acedSSGet(ACRX_T("_I"), NULL, NULL, NULL, result);
		if (iRet == RTNORM)
		{
			// There are selected entities
			// Put your command using pickfirst set code here
		}
		else
		{
			// There are no selected entities
			// Put your command code here
		}
	}

	// Application Session Command with localized name
	// ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject5App, MyGroup, MySessionCmd, MySessionCmdLocal, ACRX_CMD_MODAL | ACRX_CMD_SESSION)
	static void MyGroupMySessionCmd() {
		// Put your command code here
	}

	// The ACED_ADSFUNCTION_ENTRY_AUTO / ACED_ADSCOMMAND_ENTRY_AUTO macros can be applied to any static member 
	// function of the CArxProject5App class.
	// The function may or may not take arguments and have to return RTNORM, RTERROR, RTCAN, RTFAIL, RTREJ to AutoCAD, but use
	// acedRetNil, acedRetT, acedRetVoid, acedRetInt, acedRetReal, acedRetStr, acedRetPoint, acedRetName, acedRetList, acedRetVal to return
	// a value to the Lisp interpreter.
	//
	// NOTE: ACED_ADSFUNCTION_ENTRY_AUTO / ACED_ADSCOMMAND_ENTRY_AUTO has overloads where you can provide resourceid.

	//- ACED_ADSFUNCTION_ENTRY_AUTO(classname, name, regFunc) - this example
	//- ACED_ADSSYMBOL_ENTRYBYID_AUTO(classname, name, nameId, regFunc) - only differs that it creates a localized name using a string in the resource file
	//- ACED_ADSCOMMAND_ENTRY_AUTO(classname, name, regFunc) - a Lisp command (prefix C:)
	//- ACED_ADSCOMMAND_ENTRYBYID_AUTO(classname, name, nameId, regFunc) - only differs that it creates a localized name using a string in the resource file

	// Lisp Function is similar to ARX Command but it creates a lisp 
	// callable function. Many return types are supported not just string
	// or integer.
	// ACED_ADSFUNCTION_ENTRY_AUTO(CArxProject5App, MyLispFunction, false)
	static int ads_MyLispFunction() {
		//struct resbuf *args =acedGetArgs () ;

		// Put your command code here

		//acutRelRb (args) ;

		// Return a value to the AutoCAD Lisp Interpreter
		// acedRetNil, acedRetT, acedRetVoid, acedRetInt, acedRetReal, acedRetStr, acedRetPoint, acedRetName, acedRetList, acedRetVal

		return (RTNORM);
	}



	static void xyy_TestBlock()
	{

		AcDbBlockTableRecord *pbtr1 = new AcDbBlockTableRecord;
		AcDbBlockTableRecord *pbtr2 = new AcDbBlockTableRecord;

		pbtr1->setName(_T("vsblock"));
		pbtr2->setName(_T("nsblock"));

		AcDbBlockTable *pbt;
		acdbHostApplicationServices()->workingDatabase()->getSymbolTable(pbt, AcDb::kForWrite);

		AcDbObjectId id1, id2;
		pbt->add(id1, pbtr1);
		pbt->add(id2, pbtr2);
		pbt->close();

		AcGePoint3dArray ptarr1, ptarr2;
		ptarr1.setLogicalLength(3);
		ptarr2.setLogicalLength(4);

		ptarr1[0].set(-2.0, 3.0, 0.0);
		ptarr1[1].set(0.0, 0.0, 0.0);
		ptarr1[2].set(2.0, 3.0, 0.0);

		ptarr2[0].set(0.0, 0.0, 0.0);
		ptarr2[1].set(0.0, 2.0, 0.0);
		ptarr2[2].set(4.0, 2.0, 0.0);
		ptarr2[3].set(4.0, 0.0, 0.0);

		AcDb2dPolyline *pPline1 = new AcDb2dPolyline(AcDb::k2dSimplePoly, ptarr1, 0.0, Adesk::kFalse);
		AcDb2dPolyline *pPline2 = new AcDb2dPolyline(AcDb::k2dSimplePoly, ptarr2, 0.0, Adesk::kFalse);

		AcDbCircle *pcir = new AcDbCircle(AcGePoint3d(0.0, 0.0, 0.0), AcGeVector3d(0, 0, 1), 100);
		pbtr1->appendAcDbEntity(pPline1);
		pbtr1->appendAcDbEntity(pcir);
		pbtr2->appendAcDbEntity(pPline2);

		pbtr1->close();
		pbtr2->close();

		pPline1->close();
		pPline2->close();
		pcir->close();



	}

	static bool checkBlockName(ACHAR* strBlockName)
	{
		bool flag = false;
		AcDbBlockTable *pbt;
		acdbHostApplicationServices()->workingDatabase()->getSymbolTable(pbt, AcDb::kForRead);
		AcDbBlockTableRecord *pbtr;
		if (pbt->getAt(strBlockName, pbtr) == Acad::eOk)
		{
			flag = true;
		}
		pbt->close();
		pbtr->close();
		return flag;

	}


	//Tested OK!
	static void xyy_testbcheck()
	{
		ACHAR name[100];

		ads_getstring(NULL, _T("\nenter the block name:"), name);
		if (checkBlockName(name))
		{
			acutPrintf(_T("\n Block %s exists!"), name);
		}
		else
			acutPrintf(_T("\n Block %s doesn't exists!"), name);


	}


	static void insertBlockWithAttr(ACHAR* name, AcGePoint3d pt, ACHAR* text, double angle = 0.0, double scale = 1.0)
	{
		AcDbBlockTable *pbt;
		acdbHostApplicationServices()->workingDatabase()->getSymbolTable(pbt, AcDb::kForRead);
		AcDbBlockTableRecord *pbtr;
		if (Acad::eOk != pbt->getAt(name, pbtr, AcDb::kForRead))
		{
			acutPrintf(_T("\nblock %s doesn't exist!"), name);
			pbt->close();
			return;
		}

		AcDbObjectId blockId;
		blockId = pbtr->objectId();

		AcDbBlockReference *pbref = new AcDbBlockReference;
		pbref->setBlockTableRecord(blockId);
		pbref->setPosition(pt);
		pbref->setRotation(angle);
		pbref->setScaleFactors(scale);


		AcDbBlockTableRecordIterator *pIter;
		pbtr->newIterator(pIter);
		pbtr->close();

		AcDbEntity *pEnt = NULL;
		AcDbAttributeDefinition *pAttdef = NULL;
		AcGePoint3d basePoint;
		for (pIter->start(); !pIter->done(); pIter->step())
		{
			pIter->getEntity(pEnt, AcDb::kForRead);
			pAttdef = AcDbAttributeDefinition::cast(pEnt);
			if (pAttdef != NULL && !pAttdef->isConstant())
			{
				AcDbAttribute *pAtt = new AcDbAttribute;
				basePoint = pAttdef->position();
				basePoint += pbref->position().asVector();
				pAtt->setPosition(basePoint);
				pAtt->setHeight(pAttdef->height());
				pAtt->setTextString(text);
				pbref->appendAttribute(pAtt);
				pAtt->close();
			}
			pEnt->close();
		}
		delete pIter;
		if (pAttdef != NULL)pAttdef->close();//if(pAttdef==NULL) pAttdef can't be closed.it's important here 


		AcDbBlockTableRecord *pbtr2;
		pbt->getAt(ACDB_MODEL_SPACE, pbtr2, AcDb::kForWrite);
		pbt->close();
		AcDbObjectId brefId;
		pbtr2->appendAcDbEntity(brefId, pbref);

		pbref->close();
		pbtr2->close();

	}

	static void xyy_testInsertba()
	{
		ACHAR name[20];
		ads_getstring(NULL, _T("\nenter the block name:"), name);
		//AcGePoint3d basePoint(0.0, 0.0, 0.0);
		for (int i = 0; i < 5; i++)
		{
			AcGePoint3d pt(10.0*double(i), 20.0*double(i), 0.0);
			insertBlockWithAttr(name, pt, _T("amibaba"));
		}
	}
	static void insertBlock(ACHAR* name, AcGePoint3d pt, double angle = 0.0, double scale = 1.0)
	{
		AcDbBlockTable *pbt;
		acdbHostApplicationServices()->workingDatabase()->getSymbolTable(pbt, AcDb::kForRead);
		AcDbBlockTableRecord *pbtr;
		if (Acad::eOk != pbt->getAt(name, pbtr, AcDb::kForRead))
		{
			acutPrintf(_T("\nblock %s doesn't exist!"), name);
			pbt->close();
			return;
		}

		AcDbObjectId blockId;
		blockId = pbtr->objectId();
		pbtr->close();

		AcDbBlockReference *pbref = new AcDbBlockReference;
		pbref->setBlockTableRecord(blockId);
		pbref->setPosition(pt);
		pbref->setRotation(angle);
		pbref->setScaleFactors(scale);
		AcDbBlockTableRecord *pbtr2;
		pbt->getAt(ACDB_MODEL_SPACE, pbtr2, AcDb::kForWrite);
		pbt->close();
		AcDbObjectId brefId;
		pbtr2->appendAcDbEntity(brefId, pbref);
		pbtr2->close();
		pbref->close();
	}

	static void xyy_TestBlock2()
	{
		AcDbBlockTableRecord *pbtr = new AcDbBlockTableRecord;
		pbtr->setName(_T("yd"));
		AcGePoint3d basePoint(0.0, 0.0, 0.0);
		pbtr->setOrigin(basePoint);

		AcDbBlockTable *pbt;
		acdbHostApplicationServices()->workingDatabase()->getSymbolTable(pbt, AcDb::kForWrite);

		AcDbObjectId id;
		pbt->add(id, pbtr);
		pbt->close();



	}
	static void xyy_testInsert()
	{
		ACHAR name[20];
		ads_getstring(NULL, _T("\nenter the block name:"), name);
		//AcGePoint3d basePoint(0.0, 0.0, 0.0);
		for (int i = 0; i < 5; i++)
		{
			AcGePoint3d pt(10.0*double(i), 20.0*double(i), 0.0);
			insertBlock(name, pt);
		}
	}
	static std::vector<ACHAR*> serchBlkNames()
	{
		std::vector<ACHAR*> vNames;

		//AcDbBlockTable *pbt;
		//acdbHostApplicationServices()->workingDatabase()->getSymbolTable(pbt, AcDb::kForRead);
		//AcDbBlockTableRecord *pbtr = NULL;

		struct resbuf *rb = NULL, *bk = NULL;
		//int num = 0;
		bk = ads_tblnext(_T("BLOCK"), 1);//rewind=1 at the beginning then rewind must set to 0
		while (bk != NULL)
		{
			for (rb = bk; rb != NULL; rb = rb->rbnext)
			{
				if (rb->restype == 2)
				{
					vNames.push_back(rb->resval.rstring);
					//num++;
					//ads_printf(_T("for the %d: %s"), num, rb->resval.rstring);
					//break;
				}
			}
			bk = ads_tblnext(_T("BLOCK"), 0);
		}



		ads_relrb(rb);
		ads_relrb(bk);
		//ads_printf(_T("\n"));
		//pbt->close();
		return vNames;
	}
	static void xyy_testPrint()
	{
		// 		struct resbuf* rb=NULL;
		// 		rb = ads_tblnext(_T("BLOCK"), 1);
		// 		ads_printf(rb->resval.rstring);
		// 		ads_relrb(rb);

		for (auto& i : (serchBlkNames()))
		{
			ads_printf(_T("block name: %s \n"), i);

		}
	}
	static void xyy_blockSearch()
	{

		AcDbDatabase extDb(Adesk::kFalse);

		ACHAR dwgName[100], *blockName;

		struct resbuf fileDia, fileRes;

		ads_getvar(_T("filedia"), &fileDia);

		if (fileDia.resval.rint == 0)
		{
			fileDia.resval.rint = 1;
		}

		if (ads_getfiled(_T("\n please select a file to:"), NULL, _T("dwg"), 0, &fileRes) == RTNORM)
		{
			if (fileRes.restype == RTSTR)
			{
				_tcscpy(dwgName, fileRes.resval.rstring);
			}
			else return;
		}
		else return;
		free(fileRes.resval.rstring);
		//ads_relrb(fileRes);


		extDb.readDwgFile(dwgName);

		AcDbBlockTable *pbt;
		extDb.getBlockTable(pbt, AcDb::kForRead);
		AcDbBlockTableRecord *pbtr;
		AcDbBlockTableIterator *pIter;
		pbt->newIterator(pIter);
		for (pIter->start(); !pIter->done(); pIter->step())
		{
			pIter->getRecord(pbtr, AcDb::kForRead, Adesk::kFalse);
			pbtr->getName(blockName);
			ACHAR temp[40];
			temp[0] = *blockName;
			if (temp[0] != '*')
				ads_printf(_T("\n 块名：%s"), blockName);
		}
		delete pIter;
		pbtr->close();
		pbt->close();

	}
	static void xyy_blockSearch2()
	{
		AcDbBlockTable *pbt;
		acdbCurDwg()->getBlockTable(pbt, AcDb::kForRead);
		AcDbBlockTableIterator *pIter;
		pbt->newIterator(pIter);
		AcDbBlockTableRecord *pbtr;
		ACHAR* blockName;
		for (pIter->start(); !pIter->done(); pIter->step())
		{
			pIter->getRecord(pbtr, AcDb::kForRead, Adesk::kFalse);
			pbtr->getName(blockName);

			if (blockName[0] != '*')
			{
				ads_printf(_T("\n block Name: %s"), blockName);
			}
		}
	}
	static void xyy_blockEntitySearch()
	{
		ACHAR blockName[50];
		ads_getstring(NULL, _T("\n Enter the block name:"), blockName);

		AcDbBlockTable *pbt;
		acdbCurDwg()->getBlockTable(pbt, AcDb::kForRead);
		AcDbBlockTableRecord *pbtr;
		if (Acad::eOk != pbt->getAt(blockName, pbtr, AcDb::kForRead))
		{
			ads_printf(_T("%s doesn't exists"), blockName);
			return;
		}
		pbt->close();

		AcDbBlockTableRecordIterator *pIter;
		pbtr->newIterator(pIter);

		int num = 0;

		for (pIter->start(); !pIter->done(); pIter->step())
		{
			AcDbEntity *pEnt;
			pIter->getEntity(pEnt, AcDb::kForRead);
			ads_printf(_T("\n对象的ID：%d,类名：%s"), pEnt->objectId(), pEnt->isA()->name());
			pEnt->close();
			num++;
		}

		delete pIter;
		pbtr->close();
		ads_printf(_T("图块%s中实体总数：%d"), blockName, num);





	}
	static void changeTextHeight(AcDbText *ptxt, double h)
	{
		ptxt->setHeight(h);
	}


	static void xyy_changeTextHeight()
	{
		double h = 0.0;
		ads_getreal(_T("\n enter the text height:<5.0>"), &h);
		if (h == 0.0)
		{
			h = 5.0;
		}
		ads_printf(_T("**********************************"));
		ads_printf(_T("\n **********************%f"), h);
		AcDbBlockTable *pbt;
		acdbCurDwg()->getBlockTable(pbt, AcDb::kForRead);
		AcDbBlockTableRecord *pbtr;
		if (Acad::eOk != pbt->getAt(ACDB_MODEL_SPACE, pbtr, AcDb::kForRead))
		{
			ads_printf(_T("%s doesn't exists"), ACDB_MODEL_SPACE);
			return;
		}
		pbt->close();

		AcDbBlockTableRecordIterator *pIter;
		pbtr->newIterator(pIter);
		AcDbText *pText;
		for (pIter->start(); !pIter->done(); pIter->step())
		{
			AcDbEntity *pEnt;
			pIter->getEntity(pEnt, AcDb::kForWrite);
			if (_tcscmp(pEnt->isA()->name(), _T("AcDbText")) == 0)
			{
				ads_printf(_T("\n %d------%s "), pEnt->objectId(), pEnt->isA()->name());

				pText = AcDbText::cast(pEnt);
				ads_printf(_T("\nbefore set H=%f"), pText->height());
				pText->setHeight(h);
				ads_printf(_T("\nafter set H=%f"), pText->height());
			}
			pEnt->close();
		}
		delete pIter;
		pbtr->close();

		pText->close();

	}

	static AcDbObjectId getBlockId(const ACHAR *pBlockName)
	{
		AcDbDatabase *pCurDwg = acdbCurDwg();
		if (NULL == pCurDwg)
		{
			return AcDbObjectId::kNull;
		}
		AcDbBlockTable *pbt;
		acdbCurDwg()->getBlockTable(pbt, AcDb::kForRead);
		AcDbObjectId id;
		pbt->getAt(pBlockName, id);
		pbt->close();
		return id;

	}
	static void xyy_dfBlock()
	{

		ads_name ss, ent;
		ads_ssget(NULL, NULL, NULL, NULL, ss);

		AcDbObjectId id;
		AcDbObjectIdArray idArray;
		AcDbIdMapping map1;
		Adesk::Int32 len;
		if (RTNORM != ads_sslength(ss, &len) || 0 == len)
		{
			ads_printf(_T("nothing selected!"));
			ads_ssfree(ss);
			return;
		}

		for (Adesk::Int32 i = 0; i < len; i++)
		{
			if (RTNORM != ads_ssname(ss, i, ent))
			{
				continue;
			}
			if (Acad::eOk != acdbGetObjectId(id, ent))
			{
				continue;
			}
			idArray.append(id);
		}
		ads_ssfree(ss);

		AcDbBlockTableRecord *pbtr = new AcDbBlockTableRecord;
		ACHAR blockName[50];
		if (ads_getstring(NULL, _T("\n enter the block name:"), blockName) != RTNORM)
		{
			return;
		}
		pbtr->setName(blockName);

		AcGePoint3d basePoint(0.0, 0.0, 0.0);
		ads_getpoint(NULL, _T("\n insert point<0,0,0>:"), asDblArray(basePoint));
		pbtr->setOrigin(basePoint);
		AcDbBlockTable *pbt = NULL;
		acdbCurDwg()->getBlockTable(pbt, AcDb::kForWrite);

		pbt->add(pbtr);
		pbt->close();
		pbtr->close();

		AcDbObjectId blockId = getBlockId(blockName);

		if (Acad::eOk != acdbCurDwg()->deepCloneObjects(idArray, blockId, map1))
		{
			ads_printf(_T("\n Error in copy"));
		}


	}

	static void xyy_dBBlock()
	{
		AcDbObjectId id;
		AcDbDatabase extDb(Adesk::kFalse);
		ACHAR dwgName[50], blockName[50];
		struct resbuf fileDia, fileRes;

		ads_getvar(_T("fileDia"), &fileDia);

		if (fileDia.resval.rint == 0)
		{
			fileDia.resval.rint = 1;
		}
		if (ads_getfiled(_T("\n select file from :"), NULL, _T("dwg"), 0, &fileRes) == RTNORM)
		{
			if (fileRes.restype == RTSTR)
			{
				_tcscpy(dwgName, fileRes.resval.rstring);
			}
			else	return;
		}
		else return;


		free(fileRes.resval.rstring);

		extDb.readDwgFile(dwgName);

		AcDbDatabase *tempDb;
		extDb.wblock(tempDb);
		AcDbObjectId blockId;
		if (ads_getstring(NULL, _T("\n please enter the block name:"), blockName) == RTNORM)
		{
			acdbCurDwg()->insert(blockId, blockName, tempDb);
			acdbCurDwg()->insert(AcGeMatrix3d::kIdentity, tempDb);
			
		}
		delete tempDb;
	}
	
	static void xyy_insertFileAsBlock(ACHAR* fileName,ACHAR* blockName,AcGePoint3d pt,ACHAR* text,double angle=0.0,double scale=1.0)
	{
		AcDbDatabase *sourceDb = new AcDbDatabase(Adesk::kFalse);
		sourceDb->readDwgFile(fileName);

		AcDbDatabase *destDb;
		destDb = acdbHostApplicationServices()->workingDatabase();

		
		AcDbObjectId id;

		Acad::ErrorStatus es;
		if (Acad::eOk!=(es=destDb->insert(id,blockName,sourceDb,true)))
		{
			ads_printf(_T("Insert failed"));
			delete sourceDb;
			return;
		}
		delete sourceDb;

		AcDbBlockTable *pbt;
		acdbHostApplicationServices()->workingDatabase()->getSymbolTable(pbt, AcDb::kForRead);
		AcDbBlockTableRecord *pbtr;
		if (Acad::eOk != pbt->getAt(blockName, pbtr, AcDb::kForRead))
		{
			acutPrintf(_T("\nblock %s doesn't exist!"),blockName);
			pbt->close();
			return;
		}

		

		AcDbBlockReference *pbref = new AcDbBlockReference;
		pbref->setBlockTableRecord(id);
		pbref->setPosition(pt);
		pbref->setRotation(angle);
		pbref->setScaleFactors(scale);


		AcDbBlockTableRecordIterator *pIter;
		pbtr->newIterator(pIter);
		pbtr->close();

		AcDbEntity *pEnt = NULL;
		AcDbAttributeDefinition *pAttdef = NULL;
		AcGePoint3d basePoint;
		for (pIter->start(); !pIter->done(); pIter->step())
		{
			pIter->getEntity(pEnt, AcDb::kForRead);
			pAttdef = AcDbAttributeDefinition::cast(pEnt);
			if (pAttdef != NULL && !pAttdef->isConstant())
			{
				AcDbAttribute *pAtt = new AcDbAttribute;
				basePoint = pAttdef->position();
				basePoint += pbref->position().asVector();
				pAtt->setPosition(basePoint);
				pAtt->setHeight(pAttdef->height());
				pAtt->setTextString(text);
				pbref->appendAttribute(pAtt);
				pAtt->close();
			}
			pEnt->close();
		}
		delete pIter;
		if (pAttdef != NULL)pAttdef->close();//if(pAttdef==NULL) pAttdef can't be closed.it's important here 


		AcDbBlockTableRecord *pbtr2;
		pbt->getAt(ACDB_MODEL_SPACE, pbtr2, AcDb::kForWrite);
		pbt->close();
		AcDbObjectId brefId;
		pbtr2->appendAcDbEntity(brefId, pbref);

		pbref->close();
		pbtr2->close();



	}

	static void getFile(ACHAR* fileName)
	{
		struct resbuf fileDia, fileRes;
		acedGetVar(_T("filedia"), &fileDia);
		if (fileDia.resval.rint==0)
		{
			fileDia.resval.rint == 1;
		}
		if (ads_getfiled(_T("\n select file from:"),NULL,_T("dwg"),0,&fileRes)==RTNORM)
		{
			if (fileRes.restype==RTSTR)
			{
				_tcscpy(fileName, fileRes.resval.rstring);
			}
			else
				return;
		}
		else return;
		free(fileRes.resval.rstring);
	}

};

//-----------------------------------------------------------------------------
IMPLEMENT_ARX_ENTRYPOINT(CArxProject5App)

ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject5App, MyGroup, MyCommand, MyCommandLocal, ACRX_CMD_MODAL, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject5App, MyGroup, MyPickFirst, MyPickFirstLocal, ACRX_CMD_MODAL | ACRX_CMD_USEPICKSET, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject5App, MyGroup, MySessionCmd, MySessionCmdLocal, ACRX_CMD_MODAL | ACRX_CMD_SESSION, NULL)
ACED_ADSSYMBOL_ENTRY_AUTO(CArxProject5App, MyLispFunction, false)

ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject5App, xyy_, TestBlock, tb1, ACRX_CMD_MODAL, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject5App, xyy_, testbcheck, tb2, ACRX_CMD_MODAL, NULL)//for test is ok!
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject5App, xyy_, testInsert, tb3, ACRX_CMD_MODAL, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject5App, xyy_, testInsertba, tb4, ACRX_CMD_MODAL, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject5App, xyy_, testPrint, tb5, ACRX_CMD_MODAL, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject5App, xyy_, blockSearch, tb6, ACRX_CMD_MODAL, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject5App, xyy_, blockSearch2, tb7, ACRX_CMD_MODAL, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject5App, xyy_, blockEntitySearch, tb8, ACRX_CMD_MODAL, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject5App, xyy_, changeTextHeight, tb9, ACRX_CMD_MODAL, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject5App, xyy_, dfBlock, tb10, ACRX_CMD_MODAL, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject5App,xyy_, dBBlock,tb11,ACRX_CMD_MODAL,NULL)
//ACED_ARXCOMMAND_ENTRY_AUTO(CArxProject5App,xyy_, insertFileAsBlock,tb12,ACRX_CMD_MODAL,NULL)


