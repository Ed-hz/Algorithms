
void AddQ( Queue *PtrQ, ElementType item)
{
	if ( (PtrQ->rear+1) % MaxSize == PtrQ->front ) {
		printf("??????");
		return;
	}
	PtrQ->rear =(PtrQ->rear+1)% MaxSize;
	PtrQ->Data[PtrQ->rear] = item;
}

ElementType DeleteQ ( Queue *PtrQ )
{
	if ( PtrQ->front == PtrQ->rear ) { 
		printf("???п?");
		return ERROR;
	}
	else  {
		PtrQ->front =(PtrQ->front+1)% MaxSize;
		return  PtrQ->Data[PtrQ->front];
	}
} 
