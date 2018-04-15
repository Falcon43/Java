package jaxrs.service;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import jaxrs.jersey.database.DatabaseClass;
import jaxrs.jersey.model.Message;

public class MessageService {
	
	private Map<Long,Message> messages = DatabaseClass.getMessages();
	
	public MessageService() {
		messages.put(1L, new Message(1,"The Force will be with you. Always.", "Obi-Wan Kenobi"));
		messages.put(2L, new Message(2,"Do. Or do not. There is no try", "Yoda"));
	}
	
	public List<Message> getAllMessages(){
		return new ArrayList<Message>(messages.values());
	}

	public Message getMessage(long id){
		return messages.get(id);
	}
	
	public Message addMessage(Message message){
		message.setId(messages.size()+1);
		messages.put(message.getId(), message);
		return message;
	}
	
	public Message updateMessage(Message message){
		if(message.getId()<=0)
			return null;
		messages.put(message.getId(), message);
		return message;
	}

	public Message removeMessage(long id){
		return messages.remove(id);
	}
	
/*	
	public List<Message> getAllMessagesx(){
		Message m1 = new Message(1L, "The Force will be with you. Always.", "Obi-Wan Kenobi");
		Message m2 = new Message(2L, "Do. Or do not. There is no try", "Yoda");
		Message m3 = new Message(3L, "Never tell me the odds!", "Han Solo");
		Message m4 = new Message(4L, "I’ll never turn to the dark side. You’ve failed, your highness. I am a Jedi, like my father before me", "Luke Skywalker");
		List<Message> list = new ArrayList<Message>();
		list.add(m1);
		list.add(m2);
		list.add(m3);
		list.add(m4);
		return list;
	}
	*/

}
